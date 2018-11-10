// calculate number of tiles for 1e3, 1e6, 1e9 grains of rice
// start with 1 grain for the first tile; multiple by 2 for every subsequent tile
#include "../../../std_lib_facilities.h"

constexpr int factor = 2;
constexpr int checkFactor = 1000;
constexpr int checkLimit = 3;

int main()
{
	int	grain = 1;
	int total = 0;
	int check = checkFactor;
	int checkCount = 0;

	for (int i = 1; i < 64; ++i) {
		total += grain;
		if (total >= check && checkCount < checkLimit) {
			cout << "Tiles needed to get at least " << check << " grains = " << i << ".\n";
			check *= checkFactor;
			checkCount += 1;
		}
		grain *= factor;
	}
}