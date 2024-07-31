#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts         = 0;
int	Account::_totalAmount        = 0;
int	Account::_totalNbDeposits    = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {

    _accountIndex   = _nbAccounts;
    _amount         = initial_deposit;
    _totalAmount    += _amount;

    _displayTimestamp();
    std::cout << " index:" << _accountIndex  << ";amount:" << _amount << ";created" << std::endl;
    
    _nbAccounts++;
}

Account::~Account(void) {

    _nbAccounts = 0;

    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int Account::getNbAccounts(void) {
    return (_nbAccounts);
}

int Account::getTotalAmount(void) {
    return (_totalAmount);
}

int Account::getNbDeposits(void) {
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void) {
    return (_totalNbWithdrawals);
}
 
void	Account::displayAccountsInfos(void) {

    _displayTimestamp();
    std::cout << " accounts:" << _nbAccounts << ";total:" << _totalAmount;
    std::cout << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
} 

void Account::makeDeposit(int deposit) {

    int p_amount = _amount;
    _amount      += deposit;
    _nbDeposits++;

    _totalAmount += deposit;
    _totalNbDeposits++;

    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << p_amount << ";deposit:" << deposit;
    std::cout <<";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {

    bool    isRefused  = false;
    int     p_amount   = _amount;; 
    
    if(withdrawal > _amount)
    {
        _displayTimestamp();
        std::cout << " index:" << _accountIndex << ";p_amount:" << p_amount << ";withdrawal:refused" << std::endl;
        isRefused = true;
    }
    else
    {
        _amount     -= withdrawal;
        _nbWithdrawals++;

        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;

        _displayTimestamp();
        std::cout << " index:" << _accountIndex << ";p_amount:" << p_amount << ";withdrawal:" << withdrawal;
        std::cout << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    }
    return (isRefused);
}

int		Account::checkAmount(void) const {
    
    return (_amount);
}

void	Account::displayStatus(void) const {

    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits;
    std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void    Account::_displayTimestamp(void) {

    std::time_t		timestamp = std::time(NULL);
	char		    formattedTimestamp[20];
    
    strftime(formattedTimestamp, 20, "[%Y%m%d_%H%M%S]", localtime(&timestamp));
	std::cout << formattedTimestamp;
}
