#include<iostream>
#include<string>
#include<queue>
#include<stack>

int f(int arg) {
    if(arg==9) {
        return 0;
    }
    return arg+1;
}

int g(int arg) {
    if(arg==0) {
        return 9;
    }
    return arg-1;
}

int resolve(std::string statement) {
    std::stack<std::string> functions;
    int arg;
    while(statement.length() > 3) {
        if(statement.find("f") >= statement.find("g")){
            functions.push("g");
            statement = statement.substr(statement.find("g") + 1);
            continue;
        }
        functions.push("f");
        statement = statement.substr(statement.find("f") + 1);
        continue;
    }

    if(statement.length() == 3) {
        arg = std::stoi(statement.substr(1,1));
    }
    else {
        arg = std::stoi(statement);
    }

    while(!functions.empty()) {
        if(functions.top() == "f") {
            arg = f(arg);
            functions.pop();
            continue;
        }
        arg = g(arg);
        functions.pop();
        continue;
    }
    return arg;
}

int main(int argc, char const* argv[])
{
    std::queue<std::string> func;
    func.push("3");
    func.push("f(3)");
    func.push("g(6)");
    func.push("f(9)");
    func.push("g(0)");
    func.push("f(g(5)");
    while(!func.empty()) {
        std::cout << resolve(func.front()) << '\n';
        func.pop();
    }
    return 0;
}
