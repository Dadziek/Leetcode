bool detectCapitalUse(char* word) {
    int size = strlen(word);
    int counter = 0;

    for(int i = 0; i < size; i++){
        if(word[i] >= 65 && word[i] <= 90){
            counter ++;
        }
    }

    if(counter == size || counter == 0 || (counter == 1 && (word[0] >= 65 && word[0] <= 90))){
        return true;
    }

    return false;
}