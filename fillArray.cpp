#include <ctime>
#include <fstream>

using namespace std;

int main() {
    ofstream fout;
    fout.open("cmake-build-debug/in.txt");
    srand(time(nullptr));

    for (int i = 0; i < 12; ++i) {
        fout << rand() % 99 + 1 << "\n";
    }
    fout << rand() % 99 + 1;

    fout.close();
}
