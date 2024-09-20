int ab,k;
__libc_start_main(){
    char s[3];
    read(0, s, 3);
    ab = s[0]+s[2]-'0'*2;
    if (ab/10) s[k++]=ab/10+'0';
    s[k++]=ab%10+'0';
    write(1,s,k);
    _exit(0);
}main;