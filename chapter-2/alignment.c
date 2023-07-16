struct S {
    int i; double d; char c;
};

int main(void) {
    unsigned char bad_buff[sizeof(struct S)];
    _Alignas(struct S) unsigned char good_buff[sizeof(struct S)];
 
    struct S *bad_s_ptr = (struct S *)bad_buff;  // wrong pointer alignment
    struct S *good_s_ptr = (struct S *)good_buff;   // correct pointer alignment
}
