#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <string>

class InvestmentCalculator {
public:
    void InputData();
    void CalculateGrowth();
    void DisplayReport() const;

private:
    double m_initialAmount; // Initial amount for investment
    double m_monthlyDeposit; // Monthly deposit amount
    double m_annualInterest; // Annual interest rate
    int m_numberOfYears;
    // Vectors to store monthly calculations  with and without monthly deposits
    std::vector<double> m_monthlyOpeningAmountWithDeposit;
    std::vector<double> m_monthlyInterestWithDeposit;
    std::vector<double> m_monthlyClosingBalanceWithDeposit;
    std::vector<double> m_monthlyOpeningAmountWithoutDeposit;
    std::vector<double> m_monthlyInterestWithoutDeposit;
    std::vector<double> m_monthlyClosingBalanceWithoutDeposit;

    // Methods for calculating and reporting
    double CalculateInterest(double openingAmount) const; 
    void PrintHeader(const std::string& headerText) const; 
    void WaitForUserInput() const;
    void ClearVectors();
    void DisplayMonthlyReport(const std::vector<double>& openingAmounts, const std::vector<double>& interests, const std::vector<double>& closingBalances) const;
};


// Gets user input
void InvestmentCalculator::InputData() {
    PrintHeader("Please answer the questions provided!");
    std::cout << "What is your initial investment amount? ";
    std::cin >> m_initialAmount;

    std::cout << "What will be your monthly deposit? ";
    std::cin >> m_monthlyDeposit;

    std::cout << "What is the annual interest? For example, if you had a 5% annual interest you would enter 5. ";
    std::cin >> m_annualInterest;

    std::cout << "How many years would you like to calculate? ";
    std::cin >> m_numberOfYears;

    // Clear input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    WaitForUserInput();
}


// Calculates growth with and without monthly deposits
void InvestmentCalculator::CalculateGrowth() {
    ClearVectors();

    double openingAmountWithDeposit = m_initialAmount;
    double openingAmountWithoutDeposit = m_initialAmount;


    // Monthly calculations for user specified years
    for (int i = 0; i < m_numberOfYears * 12; ++i) {
        double interestWithDeposit = CalculateInterest(openingAmountWithDeposit + m_monthlyDeposit);
        double closingBalanceWithDeposit = openingAmountWithDeposit + m_monthlyDeposit + interestWithDeposit;

        m_monthlyOpeningAmountWithDeposit.push_back(openingAmountWithDeposit);
        m_monthlyInterestWithDeposit.push_back(interestWithDeposit);
        m_monthlyClosingBalanceWithDeposit.push_back(closingBalanceWithDeposit);


        // Calculates without monthly deposit
        double interestWithoutDeposit = CalculateInterest(openingAmountWithoutDeposit);
        double closingBalanceWithoutDeposit = openingAmountWithoutDeposit + interestWithoutDeposit;

        m_monthlyOpeningAmountWithoutDeposit.push_back(openingAmountWithoutDeposit);
        m_monthlyInterestWithoutDeposit.push_back(interestWithoutDeposit);
        m_monthlyClosingBalanceWithoutDeposit.push_back(closingBalanceWithoutDeposit);

        openingAmountWithDeposit = closingBalanceWithDeposit;  
        openingAmountWithoutDeposit = closingBalanceWithoutDeposit;  
    }
}

// Calculates monthly interest based on opening amount
double InvestmentCalculator::CalculateInterest(double openingAmount) const {
    return openingAmount * (m_annualInterest / 100.0 / 12.0);
}

void InvestmentCalculator::PrintHeader(const std::string& headerText) const {
    std::cout << "\n" << headerText << "\n" << std::string(headerText.length(), '=') << std::endl;
}

void InvestmentCalculator::WaitForUserInput() const {
    std::cout << "Press enter to generate report.";
    std::cin.get();
}

void InvestmentCalculator::ClearVectors() {
    m_monthlyOpeningAmountWithDeposit.clear();
    m_monthlyInterestWithDeposit.clear();
    m_monthlyClosingBalanceWithDeposit.clear();
    m_monthlyOpeningAmountWithoutDeposit.clear();
    m_monthlyInterestWithoutDeposit.clear();
    m_monthlyClosingBalanceWithoutDeposit.clear();
}

// Displays the monthly report
void InvestmentCalculator::DisplayReport() const {
    std::cout << std::fixed << std::setprecision(2);

    PrintHeader("Report With Additional Monthly Deposits");
    DisplayMonthlyReport(m_monthlyOpeningAmountWithDeposit, m_monthlyInterestWithDeposit, m_monthlyClosingBalanceWithDeposit);

    PrintHeader("Report Without Additional Monthly Deposits");
    DisplayMonthlyReport(m_monthlyOpeningAmountWithoutDeposit, m_monthlyInterestWithoutDeposit, m_monthlyClosingBalanceWithoutDeposit);
}

void InvestmentCalculator::DisplayMonthlyReport(const std::vector<double>& openingAmounts, const std::vector<double>& interests, const std::vector<double>& closingBalances) const {
    std::cout << std::left
        << std::setw(10) << "Month"
        << std::setw(15) << "Opening Amount"
        << std::setw(15) << "Interest"
        << std::setw(15) << "Closing Balance"
        << std::endl;
    std::cout << std::string(55, '-') << std::endl;

    for (size_t i = 0; i < openingAmounts.size(); ++i) {
        std::cout << std::left
            << std::setw(10) << i + 1
            << std::setw(15) << openingAmounts[i]
            << std::setw(15) << interests[i]
            << std::setw(15) << closingBalances[i]
            << std::endl;
    }
}


int main() {
    std::cout << "Welcome to the Airgead Banking Investment Calculator!" << std::endl;


 


    InvestmentCalculator calculator;
    calculator.InputData();
    calculator.CalculateGrowth();
    calculator.DisplayReport();


 
    // Heart and thank you
    std::cout << "\nThank you for using the Airgead Banking Investment Calculator!\n" << std::endl;
    std::cout << "        ******       ******        " << std::endl;
    std::cout << "      **      **   **      **     " << std::endl;
    std::cout << "    **         ** **         **   " << std::endl;
    std::cout << "   **            *           **   " << std::endl;
    std::cout << "   **                        **   " << std::endl;
    std::cout << "    **                      **    " << std::endl;
    std::cout << "      **                  **      " << std::endl;
    std::cout << "        **              **        " << std::endl;
    std::cout << "           **        **           " << std::endl;
    std::cout << "              **   **              " << std::endl;
    std::cout << "                 *               " << std::endl;

    return 0;
}