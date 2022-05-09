#include <cstdio>

int main( ) {
    int galleon_in, sickle_in, knut_in, galleon_in2, sickle_in2, knut_in2, galleon_bit, sickle_bit, knut_bit, galleon_ans, sickle_ans, knut_ans;
    scanf( "%d.%d.%d %d.%d.%d", &galleon_in, &sickle_in, &knut_in, &galleon_in2, &sickle_in2, &knut_in2 );
    knut_ans = ( knut_in + knut_in2 ) % 29, knut_bit = ( knut_in + knut_in2 ) / 29;
    sickle_ans = ( sickle_in + sickle_in2 + knut_bit ) % 17, sickle_bit = ( sickle_in + sickle_in2 + knut_bit ) / 17;
    galleon_ans = galleon_in + galleon_in2 + sickle_bit;
    printf( "%d.%d.%d", galleon_ans, sickle_ans, knut_ans );
    return 0;
}
