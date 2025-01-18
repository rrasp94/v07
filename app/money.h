#pragma once
#include <iostream>
#include <iomanip>

namespace vsite::oop::v7 {

	class money {
		int eur;
		int ct;

		void normalize();

	public:
		money(int eur = 0, int ct = 0);
		int get_eur() const;
		int get_ct() const;

		money& operator+=(const money& other);
		money& operator-=(const money& other);

		friend std::istream& operator>>(std::istream& is, money& m);
		friend std::ostream& operator<<(std::ostream& os, const money& m);
	};
}