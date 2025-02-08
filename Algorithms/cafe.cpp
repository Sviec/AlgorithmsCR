#include "algorithms.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void cafe() {
	int N;
	cin >> N;

	vector<int> wastes(N);

	vector<int> days;
	vector<int> coupon_days;
	int coupons = 0;
	int max_price = 0;
	int current_waste;
	int total = 0;


	for (int i = 0; i < N; ++i) {
		cin >> wastes[i];
		total += wastes[i];
	}

	for (int i = 0; i < N; ++i) {
		current_waste = wastes[i];
		if (!coupon_days.empty()) {
			if (coupon_days.size() == coupons) {
				if (coupon_days.front() < current_waste) {
					// здесь будет функция сортировки
					coupon_days.front() = current_waste;
					sort(coupon_days.begin(), coupon_days.end());
				}
			}
			else {
				// здесь будет функция сортировки
				coupon_days.push_back(current_waste);
				sort(coupon_days.begin(), coupon_days.end());
			}
		}
		else {
			if (coupons > 0) {
				coupon_days.push_back(current_waste);
			}
		}
		if (wastes[i] > 100) {
			coupons++;
		}

	}
	int used_coupons = coupon_days.size();
	int unused_coupons = coupons - coupon_days.size();
	for (int i = 0; i < coupon_days.size(); ++i) {
		total -= coupon_days[i];
	}


	cout << total << endl;
	cout << unused_coupons << " " << used_coupons << endl;
}

// написать функцию вставки элемента в вектор с сортировкой по возрастанию