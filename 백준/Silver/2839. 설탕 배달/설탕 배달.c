int main()
{
    int n;
    scanf("%d", &n);
    switch(n%5){
        case 0: 
            printf("%d\n", n / 5);
            break;
        case 1: 
            if(n - 6 < 0)
                printf("-1\n");
            else
                printf("%d\n", n / 5 + 1);
            break;
        case 2:
            if(n - 12 < 0)
                printf("-1\n");
            else
                printf("%d\n", n / 5 + 2);
            break;
        case 3:
            printf("%d\n", n / 5 + 1);
            break;
        case 4:
            if(n - 9 < 0)
                printf("-1\n");
            else
                printf("%d\n", n / 5 + 2);
    }
    return 0;
}