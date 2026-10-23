#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <algorithm>

using namespace std;

void showWelcomeMessage() {
    system("cls");
    cout << "=========================================" << endl;
    cout << "         今晚吃什么决定器 v2.0           " << endl;
    cout << "=========================================" << endl << endl;
}

int showMainMenu() {
    int choice;
    cout << "请选择操作:" << endl;
    cout << "1. 随机推荐晚餐" << endl;
    cout << "2. 重新选择(排除上次推荐)" << endl;
    cout << "3. 查看所有可选食物" << endl;
    cout << "4. 添加新的食物选项" << endl;
    cout << "5. 删除食物选项" << endl;
    cout << "6. 退出程序" << endl;
    cout << "请输入您的选择 (1-6): ";
    
    while (!(cin >> choice) || choice < 1 || choice > 6) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "输入无效，请重新输入 (1-6): ";
    }
    
    return choice;
}

void showAllFoods(const vector<string>& foods) {
    showWelcomeMessage();
    cout << "当前可选的食物有:" << endl << endl;
    
    if (foods.empty()) {
        cout << "暂无食物选项，请先添加。" << endl << endl;
    } else {
        for (size_t i = 0; i < foods.size(); ++i) {
            cout << i + 1 << ". " << foods[i] << endl;
        }
        cout << endl;
    }
    
    cout << "按回车键返回主菜单...";
    cin.ignore();
    cin.get(); 
}

// 辅助函数：获取随机推荐
string getRandomRecommendation(const vector<string>& foods) {
    if (foods.empty()) return "";
    int index = rand() % foods.size();
    return foods[index];
}

void recommendFood(const vector<string>& foods, string& lastRecommended) {
    showWelcomeMessage();
    
    if (foods.empty()) {
        cout << "暂无食物选项，请先添加。" << endl << endl;
        lastRecommended = "";
    } else {
        lastRecommended = getRandomRecommendation(foods);
        
        cout << "?? 今晚推荐您吃: " << endl << endl;
        cout << "      " << lastRecommended << "      " << endl << endl;
        cout << "祝您用餐愉快！" << endl << endl;
    }
    
    cout << "按回车键返回主菜单...";
    cin.ignore();
    cin.get(); 
}

void reselectFood(const vector<string>& allFoods, string& lastRecommended, vector<string>& excludedFoods) {
    showWelcomeMessage();
    
    if (allFoods.empty()) {
        cout << "暂无食物选项，请先添加。" << endl << endl;
        lastRecommended = "";
    } else {
        // 如果有上次推荐，将其加入排除列表
        if (!lastRecommended.empty()) {
            // 检查是否已在排除列表中
            if (find(excludedFoods.begin(), excludedFoods.end(), lastRecommended) == excludedFoods.end()) {
                excludedFoods.push_back(lastRecommended);
                cout << "已排除: " << lastRecommended << endl << endl;
            }
        }
        
        // 检查是否所有食物都被排除了
        if (excludedFoods.size() >= allFoods.size()) {
            cout << "所有食物都已被排除！" << endl;
            cout << "将重置排除列表并推荐所有食物中的一项。" << endl << endl;
            excludedFoods.clear(); // 重置排除列表
        }
        
        // 创建可用食物列表（排除已排除的选项）
        vector<string> availableFoods;
        for (const string& food : allFoods) {
            if (find(excludedFoods.begin(), excludedFoods.end(), food) == excludedFoods.end()) {
                availableFoods.push_back(food);
            }
        }
        
        // 获取新推荐
        lastRecommended = getRandomRecommendation(availableFoods);
        
        cout << "?? 新的推荐: " << endl << endl;
        cout << "      " << lastRecommended << "      " << endl << endl;
        cout << "如果仍不满意，可以再次选择重新推荐。" << endl << endl;
    }
    
    cout << "按回车键返回主菜单...";
    cin.ignore();
    cin.get(); 
}

void addFood(vector<string>& foods) {
    showWelcomeMessage();
    string newFood;
    
    cout << "请输入要添加的食物名称: ";
    cin.ignore();
    getline(cin, newFood);
    
    bool exists = false;
    for (const string& food : foods) {
        if (food == newFood) {
            exists = true;
            break;
        }
    }
    
    if (exists) {
        cout << "该食物已经存在！" << endl << endl;
    } else {
        foods.push_back(newFood);
        cout << "成功添加: " << newFood << endl << endl;
    }
    
    cout << "按回车键返回主菜单...";
    cin.get(); 
}

void removeFood(vector<string>& foods, vector<string>& excludedFoods, string& lastRecommended) {
    showWelcomeMessage();
    
    if (foods.empty()) {
        cout << "暂无食物选项，无法删除。" << endl << endl;
        cout << "按回车键返回主菜单...";
        cin.ignore();
        cin.get();
        return;
    }
    
    cout << "请选择要删除的食物 (输入编号):" << endl << endl;
    for (size_t i = 0; i < foods.size(); ++i) {
        cout << i + 1 << ". " << foods[i] << endl;
    }
    cout << endl << "输入0取消操作" << endl;
    cout << "请输入: ";
    
    int choice;
    while (!(cin >> choice) || choice < 0 || choice > static_cast<int>(foods.size())) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "输入无效，请重新输入 (0-" << foods.size() << "): ";
    }
    
    if (choice == 0) {
        cout << "已取消删除操作。" << endl << endl;
    } else {
        string removed = foods[choice - 1];
        foods.erase(foods.begin() + choice - 1);
        
        // 如果删除的是上次推荐的食物，清空上次推荐
        if (removed == lastRecommended) {
            lastRecommended = "";
        }
        
        // 如果删除的是排除列表中的食物，从排除列表中移除
        auto it = find(excludedFoods.begin(), excludedFoods.end(), removed);
        if (it != excludedFoods.end()) {
            excludedFoods.erase(it);
        }
        
        cout << "已删除: " << removed << endl << endl;
    }
    
    cout << "按回车键返回主菜单...";
    cin.ignore();
    cin.get();
}

int main() {
    vector<string> foods = {
        "火锅", "烧烤", "自选菜", "方便面", 
        "西安面馆", "鸭血粉丝", "川菜", "湘菜",
        "麻辣烫", "肠粉", "汉堡", "牛肉汤",
        "饺子","稀饭和包子","减脂餐" ,"黄焖鸡" 
    };
    
    vector<string> excludedFoods;  // 存储被排除的食物
    string lastRecommended = "";   // 存储上次推荐的食物
    int choice;
    bool running = true;
    
    // 初始化随机数生成器
    srand(time(0));
    
    while (running) {
        showWelcomeMessage();
        choice = showMainMenu();
        
        switch (choice) {
            case 1:
                // 随机推荐，重置排除列表
                excludedFoods.clear();
                recommendFood(foods, lastRecommended);
                break;
            case 2:
                // 重新选择，排除上次推荐
                reselectFood(foods, lastRecommended, excludedFoods);
                break;
            case 3:
                showAllFoods(foods);
                break;
            case 4:
                addFood(foods);
                break;
            case 5:
                removeFood(foods, excludedFoods, lastRecommended);
                break;
            case 6:
                showWelcomeMessage();
                cout << "感谢使用，再见！" << endl << endl;
                running = false;
                break;
            default:
                break;
        }
    }
    
    return 0;
}
    

