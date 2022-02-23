int main( ) {
    int start, N, K;
    cin >> start >> N >> K;
    for( int i = 0, address = 0; i < N; i++ ) {
        scanf( "%d", &address );
        scanf( "%d %d", &list[address].data, &list[address].next );
        list[address].address = address;
    }
    int cnt = 0;
    for( int p = start; p != -1; p = list[p].next )
        list[p].order = cnt++;
    sort( list, list + 100020, [] ( const node &a, const node &b ) {
        return a.order < b.order;
    } ); // 不在链表上的无效结点排在最后
    int block = cnt / K, remnant = cnt % K; // block为需要逆转的块数，remnant为最后剩下不构成一组无需逆转的结点数
    for( int i = 0; i < block; i++ ) {
        for( int j = ( i + 1 ) * K - 1; j > i * K; j-- )
            printf( "%05d %d %05d\n", list[j].address, list[j].data, list[j - 1].address );
        printf( "%05d %d", list[i * K].address, list[i * K].data );
        if( i < block - 1 ) { // 不是最后那组，正常逆转输出下一块最后一个结点的地址域
            printf( " %05d\n", list[( i + 2 ) * K - 1].address );
        } else {
            if( remnant == 0 ) { // 正好分完每个组，没有余下的结点
                printf( " -1" );
            } else { // 余下的不用逆转，从前往后正常输出
                printf( " %05d\n", list[( i + 1 ) * K].address );
                for( int j = ( i + 1 ) * K; j < cnt - 1; j++ )
                    printf( "%05d %d %05d\n", list[j].address, list[j].data, list[j + 1].address );
                printf( "%05d %d -1", list[cnt - 1].address, list[cnt - 1].data );
            }
        }
    }
    return 0;
}
