#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

#include <string>
#include <exception>

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& src);
		virtual ~Bureaucrat(void);
		Bureaucrat& operator=(Bureaucrat const& rhs);

		const std::string& getName(void) const;
		int getGrade(void) const;

		void	upGrade(void);
		void	downGrade(void);

		void	signForm(AForm& form);

		void	executeForm(AForm const & form);
		
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
    };

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
    };

		private:
			Bureaucrat(void);
			int	grade_;
			const std::string	name_;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs);

#endif
