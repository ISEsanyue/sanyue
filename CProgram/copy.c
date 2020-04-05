#include <stdio.h>
#include <math.h>

char str1[3] = "int";
char str2[5] = "float";
char str3[5] = "write";

int keyWord(char str[]) { //判断变量类型是浮点类型还是整型
    int flag = 1;
    for (int i = 0; i < 3; i++) {
        if (str[i] != str1[i]) {
            flag = 0;
            break;
        }
    }
    if (flag == 0) {
        flag = 2;
        for (int i = 0; i < 5; i++) {
            if (str[i] != str2[i]) {
                flag = 0;
                break;
            }
        }
    }
    if (flag == 0) {
        flag = 3;
        for (int i = 0; i < 5; i++) {
            if (str[i] != str3[i]) {
                flag = 0;
                break;
            }
        }
    }
    return flag;
}

int partOneLength(char str[]) { //一行中含多条语句，用于分句，返回一行中语句的数目
    int i = 0;
    while (str[i] != ';') {
        i++;
    }
    return i;
}

int complete(FILE *fr, int line, char str[]) { //判断是否分号结句，有几个分号
    int length = 0;
    int flag = 1;
    while (str[length] != '\0') {
        length++;
    }
    if (str[length - 1] != ';') {
        printf("Error(line %d): 缺少分号", line);
        flag = -1;
    } else {
        flag = 0;
        for (int i = 0; i < length; i++) {
            if (str[i] == ';') {
                flag++;
            }
        }
    }
    return flag;
}

int name(char str[], int location, char *CutName) { //截取变量名, 返回值0表示变量名首位为数字，不符合命名规范
    int i = location;
    while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'z')) {
        CutName[i - location] = str[i];
        i++;
    }
    CutName[i - location] = '\0';
    if (CutName[0] >= '0' && CutName[0] <= 9) {
        return 0;
    } else {
        return 1;
    }
}

int length(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

void clearSpace(char str[]) { //删除无意义的空格
    char copy[1000];
    int loc = 0;
    int strlen = 0;
    while (str[strlen] != '\0') {
        if (str[strlen] != ' ') {
            copy[loc] = str[strlen];
            loc++;
        }
        strlen++;
    }
    for (int i = 0; i < loc; i++) {
        str[i] = copy[i];
    }
    str[loc] = '\0';
}

int compare(char s1[], char s2[]) { //比较两个字符串，1为相等，0为不等
    int i = 0;
    if (s1[i] != '\0') {
        i++;
    }
    int j = 0;
    if (s2[j] != '\0') {
        j++;
    }
    int flag = 1;
    if (i == j) {
        for (int k = 0; k < i; k++) {
            if (s1[k] != s2[k]) {
                flag = 0;
            }
        }
    } else {
        flag = 0;
    }
    return flag;
}

int hasInit(char str[], int len) { //判断是否初始化
    int flag = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == '=') {
            flag = 1;
        }
    }
    return flag;
}

float setValue(char str[], int len) { //将初始化的值保存给对应变量
    int v = 0;
    float xiaoshu = 0;
    int xiao = 0;
    int record = 1;
    int i = 0;
    while (str[i] != '=') {
        i++;
    }
    if (i < len) {
        int j = i + 1;
        while (j < len && ((str[j] >= '0' && str[j] <= '9') || str[j] == '.')) {
            if (str[j] == '.') {
                xiao = 1;
            }
            if (xiao == 0) {
                v = v * 10 + str[j] - '0';
            } else {
                xiaoshu = xiaoshu + (str[j] - '0') * pow(10, record);
            }
            j++;
        }
    }
    return v + xiaoshu;
}

int check(char varName[50][30], char *na, int varCount) { //检查变量是否已定义，返回变量在已定义变量数组中的下标
    int find = -1;
    for (int i = 0; i < varCount; i++) {
        int j = 0;
        find = i;
        while (na[j] != '\0') {
            if (na[j] != varName[i][j]) {
                find = -1;
                break;
            }
            j++;
        }
        if (varName[i][j] != '\0') {
            find = -1;
        }
    }
    return find;
}

int main() {
    FILE *fp = NULL;
    fp = fopen("tet.txt", "w");
    fprintf(fp, "float a; \n");
    fclose(fp);
    FILE *fr = NULL;
    fr = fopen("tet.txt", "r");
    
    if ((fr = fopen("test.txt", "r")) == NULL) {
        printf("fail to read\n");
        return 1;
    }
    char str[1000];
    int line = 0;
    char varName[50][30]; //假设不多于50个变量，每个变量名字符数不超过30
    int init[50]; //变量是否被赋值
    float value[50]; //每个变量对应的值
    int varCount = 0; //计数变量个数，作为存储在varName数组里的下标
    int varType[50]; //对应相应下标的变量名数组中变量的类型，1表示int类型，2表示float
    int shown[50]; //变量是否需write进输出文件中
    while (fgets(str, 1000, (FILE*)fr) != NULL) {
        clearSpace(str);
        line++;
        int fragment = complete(fr, line, str); //一行代码中包含几条语句
        if (fragment == -1) {
            return 1;
        } else {
            int all = length(str);
            int len = partOneLength(str);
            while (fragment > 0) {
                int def = keyWord(str);
                if (def != 0) { //定义语句
                    switch (def) {
                        case 1: {
                            if (name(str, 3, varName[varCount]) == 0) {
                                printf("Error(line %d): 命名不规范 .\n", line);
                            }
                            if (hasInit(str, len)) {
                                init[varCount] = 1;
                                value[varCount] = setValue(str, all);
                            }
                            varCount++;
                            varType[varCount] = 1;
                            break;
                        }
                        case 2: {
                            if (name(str, 5, varName[varCount]) == 0) {
                                printf("Error(line %d): 命名不规范 .\n", line);
                            }
                            if (hasInit(str, all)) {
                                init[varCount] = 1;
                                value[varCount] = setValue(str, all);
                            }
                            varCount++;
                            varType[varCount] = 2;
                            break;
                        }
                        case 3: {
                            char temp[30]; //存放要输出的变量的名字
                            for (int i = 5; i < len; i++) {
                                if (str[i] == '(') {
                                    int j = i + 1;
                                    while (str[j] != ')') {
                                        if ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'z')) {
                                            temp[j - i - 1] = str[j];
                                            j++;
                                        }
                                    }
                                    break;
                                }
                            } //提取变量名
                            int index;
                            for (index = 0; index < 50; index++) {
                                if (compare(varName[index], temp)) {
                                    break;
                                }
                            }
                            if (index == 50) {
                                printf("Error(line %d): undefined identifier .\n", line);
                            } else {
                                shown[index] = 1;
                            }
                            break;
                        }
                    }
                    //if (varName[varCount][0] >= '0' && varName[varCount][0] <= '9') {
                    //    fprintf(fr, "Error(line %d): 变量名首字符必须是字母", line);
                    //}
                } else { //计算式的处理:中缀表达式转后缀表达式并求值
                    char expression[1000];
                    int count = 0;
                    while (str[count] != '=') {
                        count++;
                    }
                    char setedName[30];
                    for (int i = 0; i < count; i++) {
                        setedName[i] = str[i];
                    }
                    setedName[count] = '\0';
                    int order = check(varName, setedName, varCount);
                    if (order == -1) {
                        printf("Error(line %d): 变量未定义", line);
                    }
                    if(count >= len) {
                        break;
                    } else {
                        count++;
                        int step = count;
                        while (str[step] != ';') {
                            expression[step - count] = str[step];
                            step++;
                        }
                        expression[step - count] = '\0';
                    }
                    int i = 0;
                    char houzhui[1000];
                    int j = -1;
                    char stack[500];
                    int k = -1;
                    while (expression[i] != '\0') {
                        switch(expression[i]) {
                            case '+':
                            case '-':
                            {
                                while (k >= 0 && stack[k] != '(') {
                                    j++;
                                    houzhui[j] = stack[k];
                                    k--;
                                }
                                k++;
                                stack[k] = expression[i];
                                break;
                            }
                            case '*':
                            case '/':
                            {
                                while (k >= 0) {
                                    if (stack[k] == '*' || stack[k] == '/') {
                                        j++;
                                        houzhui[j] = stack[k];
                                        k--;
                                    } else {
                                        break;
                                    }
                                }
                                k++;
                                stack[k] = expression[i];
                                break;
                            }
                            case '(': {
                                k++;
                                stack[k] = expression[i];
                                break;
                            }
                            case ')': {
                                while (stack[k] != '(') {
                                    j++;
                                    houzhui[j] = stack[k];
                                    k--;
                                }
                            }
                            default: {
                                while ((expression[i] >= '0' && expression[i] <= '9') || (expression[i] >= 'A' && expression[i] <= 'z') || expression[i] == '.') {
                                    j++;
                                    houzhui[j] = expression[i];
                                    i++;
                                }
                                i--;
                                j++;
                                houzhui[j] = ' ';
                            }
                        }
                        i++;
                    }
                    int z = 0;
                    k = -1;
                    float stack1[500];
                    while (z <= j) {
                        if (houzhui[z] >= '0' && houzhui[z] <= '9') {
                            int keep = 0;
                            float xiaoshu = 0;
                            int xiao = 0;
                            int record = 1;
                            while ((houzhui[z] >= '0' && houzhui[z] <= '9') || houzhui[z] == '.') {
                                if (houzhui[z] == '.') {
                                    xiao = 1;
                                }
                                if (xiao == 0) {
                                    keep = 10 * keep + (houzhui[z] - '0');
                                } else {
                                    xiaoshu = xiaoshu + houzhui[z] / pow(10, record);
                                    record++;
                                }
                                z++;
                            }
                            k++;
                            stack1[k] = keep + xiaoshu;
                        } else if (houzhui[z] >= 'A' && houzhui[z] <= 'z') {
                            char namex[30];
                            int m = 0;
                            while ((houzhui[z] >= 'A' && houzhui[z] <= 'z') || (houzhui[z] >= '0' && houzhui[z] <= '9')) {
                                namex[m] = houzhui[z];
                                z++;
                                m++;
                            }
                            namex[m] = '\0';
                            int x = check(varName, namex, varCount);
                            if (x == -1) {
                                printf("Error(line %d): undefined identifier.\n", line);
                                return 0;
                            } else {
                                if (varType[x] == 1 && varType[order] == 2) {
                                    printf("Error(line %d): 整数不能转浮点数 .\n", line);
                                    return 0;
                                }
                                k++;
                                stack1[k] = value[x];
                            }
                        } else {
                            switch(houzhui[z]) {
                                case '+' : stack1[k - 1] = stack1[k] + stack1[k - 1]; k = k - 1; break;
                                case '-' : stack1[k - 1] = stack1[k] - stack1[k - 1]; k = k - 1; break;
                                case '*' : stack1[k - 1] = stack1[k] * stack1[k - 1]; k = k - 1; break;
                                case '/' : stack1[k - 1] = stack1[k] / stack1[k - 1]; k = k - 1; break;
                                default: break;
                            }
                        }
                    }
                    value[order] = stack1[0];
                }

                //复原
                fragment--;
                for (int i = 0; i < all - len; i++) {
                    str[i] = str[i + len];
                }
                str[all - len] = '\0';
            }
        }
    }
    for (int i = 0; i < varCount; i++) {
        if (shown[i] == 1) {
            printf("%f\n", value[i]);
        }
    }
    fclose(fr);
    return 0;
}
