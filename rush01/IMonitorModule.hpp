/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 19:18:24 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/21 17:50:28 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_H
#define IMONITORMODULE_H
#include <string>
#include <vector>

typedef enum e_module_type {
	mt_table = 1,
	mt_chart,
} module_type;

class IMonitorModule
{
protected:
	IMonitorModule(void);
	std::string _name;
	module_type _type;
	std::vector<double> _data;
	std::vector<std::string> _strings;
public:
	IMonitorModule(std::string, module_type);
	IMonitorModule(const IMonitorModule&);
	IMonitorModule& operator=(const IMonitorModule&);
	~IMonitorModule(void);
	std::vector<std::string> getStrings(void);
	std::vector<double> getData(void);
	std::string getName(void);
	virtual void update(void) = 0;
};

#endif
