/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:18:27 by joonhan           #+#    #+#             */
/*   Updated: 2023/02/10 09:18:28 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PhoneBook_HPP
#define PhoneBook_HPP

#define MAX_CONTACT_COUNT 8

#include "Contact.hpp"

class PhoneBook {
 private:
  int save_idx_;
  int total_count_;
  Contact contact_[MAX_CONTACT_COUNT];

 public:
  PhoneBook();

  int getTotalCount(void);
  void setTotalCount(int count);

  int getSaveIdx(void);
  void setSaveIdx(int idx);

  void addNewContact(void);

  void displayContacts(void);

  void removeOldestContact(int idx);
};

#endif
