//
// Created by eldar on 13.06.2020.
//

#ifndef GOSEXAMPLES_USERS_HPP
#define GOSEXAMPLES_USERS_HPP

#include <vector>
#include <ostream>

using namespace std;

template<class User>
class Users {
public:
    vector<User> users;
    User& operator[](int index);
};

template<class User>
User &Users<User>::operator[](int index) {
    return users[index];
}


#endif //GOSEXAMPLES_USERS_HPP
