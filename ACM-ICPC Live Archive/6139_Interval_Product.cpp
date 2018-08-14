//
// Created by ManuelLoaiza on 02/06/18.
//
#include <bits/stdc++.h>

using namespace std;

//maximum number of elements in a sequence
const int MAX_N = 1e+5;

//integers of the sequence
int X[MAX_N + 1];

//a Binary Indexed Tree structure for multiple queries and updates
struct FeinwickTree {

    //acummulated frequencies
    long long tree[MAX_N + 1];

    //set tree[] with zeros
    FeinwickTree(int N) {
        for (int i = 0; i <= N; i++) {
            tree[i] = 0;
        }
    }

    //returns the accumulated frequency
    long long query(int index) {
        long long sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= (index & - index);
        }
        return sum;
    }

    //update frequencies
    void update(int index, int delta) {
        while (index <= MAX_N) {
            tree[index] += delta;
            index += (index & - index);
        }
    }
};

int main() {
    //number of elements in each sequence
    int N;
    //number of rounds of each game
    int K;
    //test cases
    while (cin >> N >> K) {
        /*
         * I am going to accumulate the number of zeros and negative numbers
         * because they are the only ones that might make the sign of the product changes
         * if there is at least one zero, the product will be 0
         * it also depends if the number of negatives is divisible by 2
         * if it is, the sign of the product is not going to change
         * else the sign is going to change
         */
        FeinwickTree zeros(N);
        FeinwickTree negatives(N);

        //reading N integers
        for (int i = 1; i <= N; i++) {
            cin >> X[i];
            if (X[i] == 0) {
                zeros.update(i, 1);
            } else {
                if (X[i] < 0) {
                    negatives.update(i, 1);
                }
            }
        }
        
        //string containing the result of the product commands
        string answer = "";
        
        //reading K commands
        for (int i = 0; i < K; i++) {
            //uppercase letter
            // letter == 'C' : index and value
            // letter == 'P' : left and right interval product bounds
            char c;
            int l, r;
            cin >> c >> l >> r;

            if (c == 'C') {
                if (r < 0) {
                    if (X[l] == 0) {
                        zeros.update(l, -1);
                        negatives.update(l, 1);
                    }
                    if (X[l] > 0) {
                        negatives.update(l, 1);
                    }
                }
                if (r == 0) {
                    if (X[l] < 0) {
                        zeros.update(l, 1);
                        negatives.update(l, -1);
                    }
                    if (X[l] > 0) {
                        zeros.update(l, 1);
                    }
                }
                if (r > 0) {
                    if (X[l] == 0) {
                        zeros.update(l, -1);
                    }
                    if (X[l] < 0) {
                        negatives.update(l, -1);
                    }
                }

                X[l] = r;
            }

            if (c == 'P') {
                long long numberOfZeros = zeros.query(r) - zeros.query(l - 1);
                long long numberOfNegatives = negatives.query(r) - negatives.query(l - 1);

                if (numberOfZeros > 0) {
                    answer += '0';
                } else {
                    if ((numberOfNegatives % 2) == 0) {
                        answer += "+";
                    } else {
                        answer += "-";
                    }
                }
            }
        }
        cout << answer << endl;
    }

    return 0;
}
