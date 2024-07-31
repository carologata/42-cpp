#include "Account.hpp"
#include <iostream>
#include <ctime>

#define BLU "\e[0;34m" 
#define WHI "\e[0m"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {

    _accountIndex   = _nbAccounts;
    _amount         = initial_deposit;
    _totalAmount    += _amount;

    _displayTimestamp();
    std::cout << " index:" << BLU << _accountIndex  << WHI << ";amount:" << BLU << _amount << WHI << ";created" << std::endl;
    
    _nbAccounts++;
}

Account::~Account(void) {

    _nbAccounts = 0;

    _displayTimestamp();
    std::cout << " index:" << BLU << _accountIndex << WHI << ";amount:" << BLU << _amount << WHI << ";closed" << std::endl;
}

void	Account::displayAccountsInfos( void ) {

    _displayTimestamp();
    std::cout << " accounts:" << BLU << _nbAccounts << WHI << ";total:" << BLU << _totalAmount << WHI << ";deposits:" << BLU << _totalNbDeposits << WHI << ";withdrawals:" << BLU << _totalNbWithdrawals << WHI << std::endl;
} 

void Account::makeDeposit(int deposit) {

    int p_amount;

    p_amount    = _amount;
    _amount     += deposit;
    _nbDeposits++;

    _totalAmount += deposit;
    _totalNbDeposits++;

    _displayTimestamp();
    std::cout << " index:" << BLU << _accountIndex << WHI << ";p_amount:" << BLU << p_amount << WHI << ";deposit:" << BLU << deposit << WHI <<";amount:" << BLU << _amount << WHI << ";nb_deposits:" << BLU << _nbDeposits << WHI << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {

    bool isRefused;
    int p_amount; 

    isRefused = false; 
    p_amount = _amount;
    
    if(withdrawal > _amount)
    {
        _displayTimestamp();
        std::cout << " index:" << BLU << _accountIndex << WHI << ";p_amount:" << BLU << p_amount << WHI << ";withdrawal:refused" << std::endl;
        isRefused = true;
    }
    else
    {
        _amount -= withdrawal;
        _nbWithdrawals++;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;

        _displayTimestamp();
        std::cout << " index:" << BLU << _accountIndex << WHI << ";p_amount:" << BLU << p_amount << WHI << ";withdrawal:" << BLU << withdrawal << WHI << ";amount:" << BLU << _amount << WHI << ";nb_withdrawals:" << BLU << _nbWithdrawals << WHI << std::endl;
    }
    return (isRefused);
}

int		Account::checkAmount( void ) const {
    
    return (_amount);
}

void	Account::displayStatus( void ) const {

    _displayTimestamp();
    std::cout << " index:" << BLU << _accountIndex << WHI << ";amount:" << BLU << _amount << WHI << ";deposits:" << BLU << _nbDeposits << WHI << ";withdrawals:" << BLU << _nbWithdrawals << WHI << std::endl;
}

void    Account::_displayTimestamp( void ) {

    std::time_t		timestamp = std::time(NULL);
	char		    formattedTimestamp[20];
    
    strftime(formattedTimestamp, 20, "[%Y%m%d_%H%M%S]", localtime(&timestamp));
	std::cout << formattedTimestamp;
}

