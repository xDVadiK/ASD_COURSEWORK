#include "pch.h"
#include "CppUnitTest.h"
#include "..\ASD_Coursework\Calculator.h"
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ASDCourseworkUnittest
{
	TEST_CLASS(ASDCourseworkUnittest)
	{
	public:
		
		// The first example of incorrect operator input after the opening parenthesis
		TEST_METHOD(Test_Incorrect_Input_1)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			stringstream output;
			char symbol[] = "(*5+8)";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			try
			{
				Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			}
			catch (const invalid_argument error)
			{
				output << error.what();
				output << "Location of the error: " << string_expression << '\n';
				Assert::IsTrue(output.str() == "\nThe sign of the operator or the closing parenthesis cannot go immediately after the opening parenthesis\nLocation of the error: (\n");
			}
		}

		// The second example of incorrect operator input after the opening parenthesis
		TEST_METHOD(Test_Incorrect_Input_2)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			stringstream output;
			char symbol[] = "sin(4)+(^12.45*55)";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			try
			{
				Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			}
			catch (const invalid_argument error)
			{
				output << error.what();
				output << "Location of the error: " << string_expression << '\n';
				Assert::IsTrue(output.str() == "\nThe sign of the operator or the closing parenthesis cannot go immediately after the opening parenthesis\nLocation of the error: sin(4)+(\n");
			}
		}

		// The third example of incorrect operator input after the opening parenthesis
		TEST_METHOD(Test_Incorrect_Input_3)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			stringstream output;
			char symbol[] = "tg(1)+(-4)^3+()";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			try
			{
				Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			}
			catch (const invalid_argument error)
			{
				output << error.what();
				output << "Location of the error: " << string_expression << '\n';
				Assert::IsTrue(output.str() == "\nThe sign of the operator or the closing parenthesis cannot go immediately after the opening parenthesis\nLocation of the error: tg(1)+(0-4)^3+(\n");
			}
		}

		// Example of incorrect input of a set of letters
		TEST_METHOD(Test_Incorrect_Input_4)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			stringstream output;
			char symbol[] = "(scstggt)+(efjh)^2";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			try
			{
				Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			}
			catch (const invalid_argument error)
			{
				output << error.what();
				output << "Location of the error: " << string_expression << '\n';
				Assert::IsTrue(output.str() == "\nYou have entered a set of incomprehensible set of letters or a function name that is too long\nLocation of the error: (scst\n");
			}
		}

		// Example of incorrect input of an unavailable or non-existent function
		TEST_METHOD(Test_Incorrect_Input_5)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			stringstream output;
			char symbol[] = "sin(100)*atan(3)";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			try
			{
				Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			}
			catch (const invalid_argument error)
			{
				output << error.what();
				output << "Location of the error: " << string_expression << '\n';
				Assert::IsTrue(output.str() == "\nYou have entered a function that is unknown or unavailable\nLocation of the error: sin(100)*atan\n");
			}
		}

		// Example of incorrect input of a function that requires an argument
		TEST_METHOD(Test_Incorrect_Input_6)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			stringstream output;
			char symbol[] = "asin(1)^2-cos+5";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			try
			{
				Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			}
			catch (const invalid_argument error)
			{
				output << error.what();
				output << "Location of the error: " << string_expression << '\n';
				Assert::IsTrue(output.str() == "\nDo not enter an argument for the entered function\nLocation of the error: asin(1)^2-cos\n");
			}
		}

		// Example of incorrect input of a number starting from zero
		TEST_METHOD(Test_Incorrect_Input_7)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			stringstream output;
			char symbol[] = "0bcd+exp(2)";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			try
			{
				Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			}
			catch (const invalid_argument error)
			{
				output << error.what();
				output << "Location of the error: " << string_expression << '\n';
				Assert::IsTrue(output.str() == "\nAfter an integer zero, you need to put a dot or a sign of the operator\nLocation of the error: 0\n");
			}
		}

		// The first example of incorrect input of two dots into a real number
		TEST_METHOD(Test_Incorrect_Input_8)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			stringstream output;
			char symbol[] = "(4+5^2)*(12.2.23+40)";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			try
			{
				Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			}
			catch (const invalid_argument error)
			{
				output << error.what();
				output << "Location of the error: " << string_expression << '\n';
				Assert::IsTrue(output.str() == "\nYou have entered an extra point in the real number\nLocation of the error: (4+5^2)*(12.2\n");
			}
		}

		// The first example of incorrect input of operator characters in the real part of a number
		TEST_METHOD(Test_Incorrect_Input_9)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			stringstream output;
			char symbol[] = "(0.fff+0.55^2)^4";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			try
			{
				Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			}
			catch (const invalid_argument error)
			{
				output << error.what();
				output << "Location of the error: " << string_expression << '\n';
				Assert::IsTrue(output.str() == "\nThe real part of the number must consist of digits\nLocation of the error: (0.\n");
			}
		}

		// The second example of incorrect input of two dots into a real number
		TEST_METHOD(Test_Incorrect_Input_10)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			stringstream output;
			char symbol[] = "log(7.45.4)*exp(5)^(45-43)";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			try
			{
				Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			}
			catch (const invalid_argument error)
			{
				output << error.what();
				output << "Location of the error: " << string_expression << '\n';
				Assert::IsTrue(output.str() == "\nYou have entered an extra point in the real number\nLocation of the error: log(7.45\n");
			}
		}

		// The second example of incorrect input of operator characters in the real part of a number
		TEST_METHOD(Test_Incorrect_Input_11)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			stringstream output;
			char symbol[] = "exp(45.ggg)-(-5+exp(30-29))";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			try
			{
				Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			}
			catch (const invalid_argument error)
			{
				output << error.what();
				output << "Location of the error: " << string_expression << '\n';
				Assert::IsTrue(output.str() == "\nThe real part of the number must consist of digits\nLocation of the error: exp(45.\n");
			}
		}

		// Example of incorrect input of operator characters in the real part of a number
		TEST_METHOD(Test_Incorrect_Input_12)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			stringstream output;
			char symbol[] = "(555.***+54)";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			try
			{
				Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			}
			catch (const invalid_argument error)
			{
				output << error.what();
				output << "Location of the error: " << string_expression << '\n';
				Assert::IsTrue(output.str() == "\nThe real part of the number must consist of digits\nLocation of the error: (555.\n");
			}
		}

		// Example of incorrect input of an opening parenthesis after a digit
		TEST_METHOD(Test_Incorrect_Input_13)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			stringstream output;
			char symbol[] = "(-40+ln(100()";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			try
			{
				Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			}
			catch (const invalid_argument error)
			{
				output << error.what();
				output << "Location of the error: " << string_expression << '\n';
				Assert::IsTrue(output.str() == "\nOpening bracket cannot go immediately after a digit without an operator\nLocation of the error: (0-40+ln(100\n");
			}
		}

		// Example of incorrect input of a letter after a number
		TEST_METHOD(Test_Incorrect_Input_14)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			stringstream output;
			char symbol[] = "230a^(45-log(35))";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			try
			{
				Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			}
			catch (const invalid_argument error)
			{
				output << error.what();
				output << "Location of the error: " << string_expression << '\n';
				Assert::IsTrue(output.str() == "\nLetter cannot go immediately after a digit without an operator\nLocation of the error: 230\n");
			}
		}

		// Example of incorrect operator input at the end of a mathematical expression
		TEST_METHOD(Test_Incorrect_Input_15)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			stringstream output;
			char symbol[] = "1200+450-700+";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			try
			{
				Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			}
			catch (const invalid_argument error)
			{
				output << error.what();
				output << "Location of the error: " << string_expression << '\n';
				Assert::IsTrue(output.str() == "\nA mathematical expression cannot end with an operator sign\nLocation of the error: 1200+450-700\n");
			}
		}

		// Example of incorrect input of two operators in a row
		TEST_METHOD(Test_Incorrect_Input_16)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			stringstream output;
			char symbol[] = "sin(1)++cos(0)";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			try
			{
				Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			}
			catch (const invalid_argument error)
			{
				output << error.what();
				output << "Location of the error: " << string_expression << '\n';
				Assert::IsTrue(output.str() == "\nIn a mathematical expression, two operators cannot go in a row without divisions\nLocation of the error: sin(1)+\n");
			}
		}
		
		// Example of incorrect input of a closing parenthesis after the operator
		TEST_METHOD(Test_Incorrect_Input_17)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			stringstream output;
			char symbol[] = "((ln(1)+ln(2)+ln(3))*)";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			try
			{
				Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			}
			catch (const invalid_argument error)
			{
				output << error.what();
				output << "Location of the error: " << string_expression << '\n';
				Assert::IsTrue(output.str() == "\nThe symbol ')' cannot go immediately after the operator\nLocation of the error: ((ln(1)+ln(2)+ln(3))*\n");
			}
		}

		// Example of incorrect input of closing brackets more than opening ones
		TEST_METHOD(Test_Incorrect_Input_18)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			stringstream output;
			char symbol[] = "(cos(0)+sin(3)))";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			try
			{
				Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			}
			catch (const invalid_argument error)
			{
				output << error.what();
				output << "Location of the error: " << string_expression << '\n';
				Assert::IsTrue(output.str() == "\nThere cannot be more closing brackets than opening ones\nLocation of the error: (cos(0)+sin(3))\n");
			}
		}

		// Example of incorrect input of a letter after a closing parenthesis
		TEST_METHOD(Test_Incorrect_Input_19)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			stringstream output;
			char symbol[] = "(ln(1)a+5)";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			try
			{
				Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			}
			catch (const invalid_argument error)
			{
				output << error.what();
				output << "Location of the error: " << string_expression << '\n';
				Assert::IsTrue(output.str() == "\nThe letter cannot go immediately after the closing parenthesis without the operator\nLocation of the error: (ln(1)\n");
			}
		}

		// Example of incorrect digit input after closing parenthesis
		TEST_METHOD(Test_Incorrect_Input_20)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			stringstream output;
			char symbol[] = "((58+42)4-8)";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			try
			{
				Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			}
			catch (const invalid_argument error)
			{
				output << error.what();
				output << "Location of the error: " << string_expression << '\n';
				Assert::IsTrue(output.str() == "\nThe digit cannot go immediately after the closing parenthesis without the operator\nLocation of the error: ((58+42)\n");
			}
		}

		// Example of incorrect input of an opening parenthesis after a closing parenthesis
		TEST_METHOD(Test_Incorrect_Input_21)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			stringstream output;
			char symbol[] = "(ctg(1)+40)(sin(40)+30)";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			try
			{
				Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			}
			catch (const invalid_argument error)
			{
				output << error.what();
				output << "Location of the error: " << string_expression << '\n';
				Assert::IsTrue(output.str() == "\nSymbols ')' and '(' cannot go in this sequence without the operator\nLocation of the error: (ctg(1)+40)\n");
			}
		}

		// Example of incorrect input of a closing parenthesis at the beginning of a mathematical expression
		TEST_METHOD(Test_Incorrect_Input_22)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			stringstream output;
			char symbol[] = ")sin(5)+6";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			try
			{
				Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			}
			catch (const invalid_argument error)
			{
				output << error.what();
				if (!string_expression.string_is_empty())
				{
					output << "Location of the error: " << string_expression << '\n';
				}
				else output << "Location of the error: the first symbol\n";
				Assert::IsTrue(output.str() == "\nThere cannot be more closing brackets than opening ones\nLocation of the error: the first symbol\n");
			}
		}

		// The first example of entering unavailable characters
		TEST_METHOD(Test_Incorrect_Input_23)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			stringstream output;
			char symbol[] = "cos(0)=1";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			try
			{
				Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			}
			catch (const invalid_argument error)
			{
				output << error.what();
				output << "Location of the error: " << string_expression << '\n';
				Assert::IsTrue(output.str() == "\nSymbols unrecognized by the program were entered\nLocation of the error: cos(0)\n");
			}
		}

		// The second example of entering unavailable characters
		TEST_METHOD(Test_Incorrect_Input_24)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			stringstream output;
			char symbol[] = "4+5?*cos(40)";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			try
			{
				Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			}
			catch (const invalid_argument error)
			{
				output << error.what();
				output << "Location of the error: " << string_expression << '\n';
				Assert::IsTrue(output.str() == "\nSymbols unrecognized by the program were entered\nLocation of the error: 4+5\n");
			}
		}

		// The second example of entering unavailable characters
		TEST_METHOD(Test_Incorrect_Input_25)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			stringstream output;
			char symbol[] = "4+5?*cos(40)";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			try
			{
				Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			}
			catch (const invalid_argument error)
			{
				output << error.what();
				output << "Location of the error: " << string_expression << '\n';
				Assert::IsTrue(output.str() == "\nSymbols unrecognized by the program were entered\nLocation of the error: 4+5\n");
			}
		}

		// Example of incorrect input when skipping the closing parenthesis
		TEST_METHOD(Test_Incorrect_Input_26)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			stringstream output;
			char symbol[] = "(exp(6)+exp(7)";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			try
			{
				Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			}
			catch (const invalid_argument error)
			{
				output << error.what();
				output << "Location of the error: " << string_expression << '\n';
				Assert::IsTrue(output.str() == "\nYou missed the closing parenthesis\nLocation of the error: (exp(6)+exp(7)\n");
			}
		}

		// Attempt to display an empty string on the screen
		TEST_METHOD(Test_String_is_empty)
		{
			String_mathematical_expression mathematical_expression;
			stringstream output;
			try
			{
				cout << mathematical_expression;
			}
			catch (const domain_error error)
			{
				output << error.what();
				Assert::IsTrue(output.str() == "\nThe string of the mathematical expression is empty\n");
			}
		}

		// Error of translation into infix form in the absence of a mathematical expression
		TEST_METHOD(Test_Infix_Form_is_empty)
		{
			Queue infix_form;
			Queue postfix_form;
			stringstream output;
			try
			{
				Conversion_to_postfix_form(infix_form, postfix_form);
			}
			catch (const domain_error error)
			{
				output << error.what();
				Assert::IsTrue(output.str() == "\nThere is no mathematical expression in the infix\n");
			}
		}

		// Emptiness of a queue storing a mathematical expression in postfix form
		TEST_METHOD(Test_Postfix_Form_is_empty)
		{
			Queue postfix_form;
			stringstream output;
			try
			{
				cout << Calculating_the_value(postfix_form);
			}
			catch (const domain_error error)
			{
				output << error.what();
				Assert::IsTrue(output.str() == "\nThe queue with the postfix form of the mathematical expression is empty\n");
			}
		}

		// The first example of converting the infix form of a record in to a postfix form
		TEST_METHOD(Test_Conversion_to_Postfix_Form_1)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			Queue postfix_form;
			stringstream output;
			char symbol[] = "-5*cos(0)";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			Conversion_to_postfix_form(infix_form, postfix_form);
			Element_mathematical_expression* element;
			while (!postfix_form.queue_is_empty()) 
			{
				element = postfix_form.dequeue();
				double digit_or_priority = element->get_digit_or_priority_value(element); 
			    string operator_value = element->get_operator_value(element); 
				if (operator_value == "D") 
				{
					output << element->get_digit_or_priority_value(element) << " ";;
				}
				else output << element->get_operator_value(element) << " ";
			}
			Assert::IsTrue(output.str() == "0 5 0 cos * - ");
		}

		// The second example of converting the infix form of a record in to a postfix form
		TEST_METHOD(Test_Conversion_to_Postfix_Form_2)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			Queue postfix_form;
			stringstream output;
			char symbol[] = "(cos(0)+sin(35)*(55-85))";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			Conversion_to_postfix_form(infix_form, postfix_form);
			Element_mathematical_expression* element;
			while (!postfix_form.queue_is_empty())
			{
				element = postfix_form.dequeue();
				double digit_or_priority = element->get_digit_or_priority_value(element);
				string operator_value = element->get_operator_value(element);
				if (operator_value == "D")
				{
					output << element->get_digit_or_priority_value(element) << " ";;
				}
				else output << element->get_operator_value(element) << " ";
			}
			Assert::IsTrue(output.str() == "0 cos 35 sin 55 85 - * + ");
		}

		// The third example of converting the infix form of a record in to a postfix form
		TEST_METHOD(Test_Conversion_to_Postfix_Form_3)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			Queue postfix_form;
			stringstream output;
			char symbol[] = "sqrt(24.5^2)+45-5.55";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			Conversion_to_postfix_form(infix_form, postfix_form);
			Element_mathematical_expression* element;
			while (!postfix_form.queue_is_empty())
			{
				element = postfix_form.dequeue();
				double digit_or_priority = element->get_digit_or_priority_value(element);
				string operator_value = element->get_operator_value(element);
				if (operator_value == "D")
				{
					output << element->get_digit_or_priority_value(element) << " ";;
				}
				else output << element->get_operator_value(element) << " ";
			}
			Assert::IsTrue(output.str() == "24.5 2 ^ sqrt 45 + 5.55 - ");
		}

		// The fourth example of converting the infix form of a record in to a postfix form
		TEST_METHOD(Test_Conversion_to_Postfix_Form_4)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			Queue postfix_form;
			stringstream output;
			char symbol[] = "(ln(50)*3.5)+35.5*(44-42)";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			Conversion_to_postfix_form(infix_form, postfix_form);
			Element_mathematical_expression* element;
			while (!postfix_form.queue_is_empty())
			{
				element = postfix_form.dequeue();
				double digit_or_priority = element->get_digit_or_priority_value(element);
				string operator_value = element->get_operator_value(element);
				if (operator_value == "D")
				{
					output << element->get_digit_or_priority_value(element) << " ";;
				}
				else output << element->get_operator_value(element) << " ";
			}
			Assert::IsTrue(output.str() == "50 ln 3.5 * 35.5 44 42 - * + ");
		}

		// The fifth example of converting the infix form of a record in to a postfix form
		TEST_METHOD(Test_Conversion_to_Postfix_Form_5)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			Queue postfix_form;
			stringstream output;
			char symbol[] = "(((5+4)^2+(5.55-0.55)^2)-(100*2-50))";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			Conversion_to_postfix_form(infix_form, postfix_form);
			Element_mathematical_expression* element;
			while (!postfix_form.queue_is_empty())
			{
				element = postfix_form.dequeue();
				double digit_or_priority = element->get_digit_or_priority_value(element);
				string operator_value = element->get_operator_value(element);
				if (operator_value == "D")
				{
					output << element->get_digit_or_priority_value(element) << " ";;
				}
				else output << element->get_operator_value(element) << " ";
			}
			Assert::IsTrue(output.str() == "5 4 + 2 ^ 5.55 0.55 - 2 ^ + 100 2 * 50 - - ");
		}

		// The sixth example of converting the infix form of a record in to a postfix form
		TEST_METHOD(Test_Conversion_to_Postfix_Form_6)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			Queue postfix_form;
			stringstream output;
			char symbol[] = "(-(-4+5)+ln(1)+ln(2)+ln(3))";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			Conversion_to_postfix_form(infix_form, postfix_form);
			Element_mathematical_expression* element;
			while (!postfix_form.queue_is_empty())
			{
				element = postfix_form.dequeue();
				double digit_or_priority = element->get_digit_or_priority_value(element);
				string operator_value = element->get_operator_value(element);
				if (operator_value == "D")
				{
					output << element->get_digit_or_priority_value(element) << " ";;
				}
				else output << element->get_operator_value(element) << " ";
			}
			Assert::IsTrue(output.str() == "0 0 4 - 5 + - 1 ln 2 ln 3 ln + + + ");
		}

		// The seventh example of converting the infix form of a record in to a postfix form
		TEST_METHOD(Test_Conversion_to_Postfix_Form_7)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			Queue postfix_form;
			stringstream output;
			char symbol[] = "(cos(5)^2+(sin(5)-100)+50/5)";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			Conversion_to_postfix_form(infix_form, postfix_form);
			Element_mathematical_expression* element;
			while (!postfix_form.queue_is_empty())
			{
				element = postfix_form.dequeue();
				double digit_or_priority = element->get_digit_or_priority_value(element);
				string operator_value = element->get_operator_value(element);
				if (operator_value == "D")
				{
					output << element->get_digit_or_priority_value(element) << " ";;
				}
				else output << element->get_operator_value(element) << " ";
			}
			Assert::IsTrue(output.str() == "5 cos 2 ^ 5 sin 100 - + 50 5 / + ");
		}

		// The eighth example of converting the infix form of a record in to a postfix form
		TEST_METHOD(Test_Conversion_to_Postfix_Form_8)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			Queue postfix_form;
			stringstream output;
			char symbol[] = "(sqrt(100)^(2+2)-(1000+50/5*0))";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			Conversion_to_postfix_form(infix_form, postfix_form);
			Element_mathematical_expression* element;
			while (!postfix_form.queue_is_empty())
			{
				element = postfix_form.dequeue();
				double digit_or_priority = element->get_digit_or_priority_value(element);
				string operator_value = element->get_operator_value(element);
				if (operator_value == "D")
				{
					output << element->get_digit_or_priority_value(element) << " ";;
				}
				else output << element->get_operator_value(element) << " ";
			}
			Assert::IsTrue(output.str() == "100 sqrt 2 2 + ^ 1000 50 5 / 0 * + - ");
		}

		// The ninth example of converting the infix form of a record in to a postfix form
		TEST_METHOD(Test_Conversion_to_Postfix_Form_9)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			Queue postfix_form;
			stringstream output;
			char symbol[] = "(1+(1-1)+(1-1)+1)";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			Conversion_to_postfix_form(infix_form, postfix_form);
			Element_mathematical_expression* element;
			while (!postfix_form.queue_is_empty())
			{
				element = postfix_form.dequeue();
				double digit_or_priority = element->get_digit_or_priority_value(element);
				string operator_value = element->get_operator_value(element);
				if (operator_value == "D")
				{
					output << element->get_digit_or_priority_value(element) << " ";;
				}
				else output << element->get_operator_value(element) << " ";
			}
			Assert::IsTrue(output.str() == "1 1 1 - + 1 1 - + 1 + ");
		}

		// The tenth example of converting the infix form of a record in to a postfix form
		TEST_METHOD(Test_Conversion_to_Postfix_Form_10)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			Queue postfix_form;
			stringstream output;
			char symbol[] = "(450-(5^3-cos(0)*5)+56^1)";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			Conversion_to_postfix_form(infix_form, postfix_form);
			Element_mathematical_expression* element;
			while (!postfix_form.queue_is_empty())
			{
				element = postfix_form.dequeue();
				double digit_or_priority = element->get_digit_or_priority_value(element);
				string operator_value = element->get_operator_value(element);
				if (operator_value == "D")
				{
					output << element->get_digit_or_priority_value(element) << " ";;
				}
				else output << element->get_operator_value(element) << " ";
			}
			Assert::IsTrue(output.str() == "450 5 3 ^ 0 cos 5 * - - 56 1 ^ + ");
		}

		// The first example of calculating a value with correct input
		TEST_METHOD(Test_Calculating_the_Value_1)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			Queue postfix_form;
			char symbol[] = "(1500-25^3+55-100^2)";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			Conversion_to_postfix_form(infix_form, postfix_form);
			double result = Calculating_the_value(postfix_form);
			Assert::IsTrue(result == -4180);
		}

		// The second example of calculating a value with the correct input
		TEST_METHOD(Test_Calculating_the_Value_2)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			Queue postfix_form;
			char symbol[] = "sqrt(10000)-100+50^2";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			Conversion_to_postfix_form(infix_form, postfix_form);
			double result = Calculating_the_value(postfix_form);
			Assert::IsTrue(result == 2500);
		}

		// The third example of calculating a value with the correct input
		TEST_METHOD(Test_Calculating_the_Value_3)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			Queue postfix_form;
			char symbol[] = "(40+50.50)/5+((45-5)*4)^2";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			Conversion_to_postfix_form(infix_form, postfix_form);
			double result = Calculating_the_value(postfix_form);
			Assert::IsTrue(result == 25618.1);
		}

		// The fourth example of calculating a value with the correct input
		TEST_METHOD(Test_Calculating_the_Value_4)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			Queue postfix_form;
			char symbol[] = "(cos(0)*50+log(100)-ln(1)*500)";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			Conversion_to_postfix_form(infix_form, postfix_form);
			double result = Calculating_the_value(postfix_form);
			Assert::IsTrue(result == 52);
		}

		// The fifth example of calculating a value with the correct input
		TEST_METHOD(Test_Calculating_the_Value_5)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			Queue postfix_form;
			char symbol[] = "((exp(0)*50)+(sin(0)*5)+(45.5^2-45)+5-0.25)";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			Conversion_to_postfix_form(infix_form, postfix_form);
			double result = Calculating_the_value(postfix_form);
			Assert::IsTrue(result == 2080);
		}

		// The sixth example of calculating a value with the correct input
		TEST_METHOD(Test_Calculating_the_Value_6)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			Queue postfix_form;
			char symbol[] = "(1+2+3+4+5)^2-100+75.5";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			Conversion_to_postfix_form(infix_form, postfix_form);
			double result = Calculating_the_value(postfix_form);
			Assert::IsTrue(result == 200.5);
		}

		// The seventh example of calculating a value with the correct input
		TEST_METHOD(Test_Calculating_the_Value_7)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			Queue postfix_form;
			char symbol[] = "((sqrt(100)+10)^2)+20";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			Conversion_to_postfix_form(infix_form, postfix_form);
			double result = Calculating_the_value(postfix_form);
			Assert::IsTrue(result == 420);
		}

		// The eighth example of calculating a value with the correct input
		TEST_METHOD(Test_Calculating_the_Value_8)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			Queue postfix_form;
			char symbol[] = "(((1+1)*5)+((2+2)*3)+((3+3)*1))^2";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			Conversion_to_postfix_form(infix_form, postfix_form);
			double result = Calculating_the_value(postfix_form);
			Assert::IsTrue(result == 784);
		}

		// The ninth example of calculating a value with the correct input
		TEST_METHOD(Test_Calculating_the_Value_9)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			Queue postfix_form;
			char symbol[] = "(-15000+((50*10)*(75*5))/5+50/(2*3-1))";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			Conversion_to_postfix_form(infix_form, postfix_form);
			double result = Calculating_the_value(postfix_form);
			Assert::IsTrue(result == 22510);
		}

		// The tenth example of calculating a value with the correct input
		TEST_METHOD(Test_Calculating_the_Value_10)
		{
			String_mathematical_expression mathematical_expression;
			String_mathematical_expression string_expression;
			Queue infix_form;
			Queue postfix_form;
			char symbol[] = "(100/(200/50+8*2-4*4)+(125.76-15.26))";
			for (int index = 0; symbol[index] != '\0'; index++)
			{
				mathematical_expression.add_symbol(symbol[index]);
			}
			Check_correctness_expression(mathematical_expression, string_expression, infix_form);
			Conversion_to_postfix_form(infix_form, postfix_form);
			double result = Calculating_the_value(postfix_form);
			Assert::IsTrue(result == 135.5);
		}
	};
}
