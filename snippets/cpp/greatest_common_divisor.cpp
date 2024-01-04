
int gcd(int x, int y) {
    int remainder;

    while(x > 0) {
        remainder = x % y;
        x = y;
        y = remainder;
    }

    return y;
}