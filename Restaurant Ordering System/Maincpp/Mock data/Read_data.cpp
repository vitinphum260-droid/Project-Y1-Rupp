#include <array>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <variant>

using namespace std;

namespace {

constexpr size_t MAX_MENU_ITEMS = 100;

struct MenuRow {
    string productName;
    variant<double, string> price;
};

string formatPrice(const variant<double, string>& price) {
    if (const double* usd = get_if<double>(&price)) {
        ostringstream output;
        output << '$' << fixed << setprecision(2) << *usd;
        return output.str();
    }

    return get<string>(price);
}

bool readMenuData(const string& fileName,
                  array<MenuRow, MAX_MENU_ITEMS>& menuItems,
                  size_t& rowCount) {
    ifstream input(fileName);
    if (!input) {
        return false;
    }

    string line;
    getline(input, line); // just read and over: Product Name,Price

    rowCount = 0;
    while (rowCount < menuItems.size() && getline(input, line)) {
        const size_t comma = line.rfind(',');
        if (comma == string::npos) {
            continue;
        }

        MenuRow& row = menuItems[rowCount];
        row.productName = line.substr(0, comma);
        string priceText = line.substr(comma + 1);

        try {
            if (!priceText.empty() && priceText.back() == '$') {
                priceText.pop_back(); // delete $
                row.price = stod(priceText); // throw number after delete $ to row price
            } else {
                row.price = priceText;
            }
        } catch (const exception&) {
            row.price = priceText;
        }

        ++rowCount;
    }

    return true;
}

void printTable(const array<MenuRow, MAX_MENU_ITEMS>& menuItems,
                size_t rowCount) {
    constexpr int NUMBER_WIDTH = 5;
    constexpr int PRODUCT_WIDTH = 28;
    constexpr int PRICE_WIDTH = 12;

    const string border = "+-----+----------------------------+------------+";
    cout << border << '\n';
    cout << "| " << left << setw(NUMBER_WIDTH - 2) << "No"
         << "| " << setw(PRODUCT_WIDTH - 2) << "Product Name"
         << "| " << setw(PRICE_WIDTH - 2) << "Price" << "|\n";
    cout << border << '\n';

    for (size_t index = 0; index < rowCount; ++index) {
        cout << "| " << left << setw(NUMBER_WIDTH - 2) << index + 1
             << "| " << setw(PRODUCT_WIDTH - 2) << menuItems[index].productName
             << "| " << setw(PRICE_WIDTH - 2) << formatPrice(menuItems[index].price)
             << "|\n";
    }

    cout << border << '\n';
    cout << "Total rows: " << rowCount << '\n';
}

} // namespace

int main() {
    array<MenuRow, MAX_MENU_ITEMS> menuItems{};
    size_t rowCount = 0;

    if (!readMenuData("data.csv", menuItems, rowCount)) {
        cerr << "Could not open data.csv. Run this program from the Mock data folder.\n";
        return 1;
    }

    printTable(menuItems, rowCount);
    return 0;
}
 