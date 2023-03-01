#ifndef Form_HPP
# define Form_HPP

#include <string>
#include <exception>

class Bureaucrat;

class Form
{
	public:
		Form(const std::string& name, int sign_grade, int execute_grade);
		Form(const Form& src);
		virtual ~Form(void);
		Form& operator=(Form const& rhs);

		const std::string& getName(void) const;

		bool getIsSigned(void) const;
		void	setIsSigned(bool status);

		int getSignGrade(void) const;

		int getExecuteGrade(void) const;

		void	beSigned(Bureaucrat& person);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
    };

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
    };

		private:
			Form(void);

			const std::string	name_;
			bool	is_signed_;
			const int	sign_grade_;
			const int	execute_grade_;
};

std::ostream& operator<<(std::ostream& out, const Form& rhs);

#endif
