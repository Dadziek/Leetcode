bool isValid(char* s){
    char match[256] = {0};
    match['('] = ')';
    match['['] = ']';
    match['{'] = '}';

    int len = strlen(s);
    char stack[len];
    int top = -1;

    for (int i = 0; i < len; i++) {
        char c = s[i];

        if (match[c] != 0) {
            stack[++top] = c;
        } 

        else {
            if (top == -1 || match[stack[top]] != c) {
                return false;
            }
            top--;
        }
    }
    return top == -1;
}