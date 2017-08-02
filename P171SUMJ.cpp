#include "bits/stdc++.h"
#include "stdio.h"
using	namespace std;

main()
{
	long double a, b, c;
	long double delta, x1, x2;

	cin >> a >> b >> c;
	delta = b*b - 4 * a*c;
	if( a != 0 ) {
		if( delta > 0 ) {
			x1 = ( -b - sqrt(delta) ) / ( 2 * a );
			x2 = ( -b + sqrt(delta) ) / ( 2 * a );
			if(x1>x2) swap(x1,x2);
			printf( "2\n%.5f\n%.5f", (double)x1, (double)x2 );
		}
		else if( delta == 0 ) {
			x1 = -b/(2*a );
			printf("1\n%.5f", (double)x1);
		}
		else {
			cout << 0;
		}
	}
	else {
		if( b != 0 ) {
			x1 = -c / b ;
			printf( "1\n%.5f", double(x1));
		}
		else {
			if( c != 0 ) {
				cout << 0;
			}
			else {
				cout << -1;
			}
		}
	}
}
