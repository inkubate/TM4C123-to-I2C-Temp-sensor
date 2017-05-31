
void delay(int time) {
    for(int volatile counter = 0; counter < time; counter++){}
}