#pragma once
#include <iostream>
#include <sstream>

using namespace std;

// Priorities of supported characters
enum Priority_allocation
{
	parenthesis = 0,
	plus_and_minus_operator = 1,
	multiplication_and_division_operator = 2,
	exponentiation_operator = 3,
	symbol_is_not_an_operator = 4,
};

// List of supported functions and constants
enum Available_functions_and_constants
{
	function_cos = 0,
	function_sin = 1,
	function_tg = 2,
	function_ctg = 3,
	function_ln = 4,
	function_log = 5,
	function_sqrt = 6,
	function_asin = 7,
	function_acos = 8,
	constant_pi = 9,
	constant_exp = 10,
	unknown_function = 11,
	other_constant = 12,
};

// The class of an element of a mathematical expression
class Element_mathematical_expression
{
	double digit_or_priority; // A variable for storing the value of a digit or operator priority
	Element_mathematical_expression* next;

	// A class for storing the operator value as a list
	class Element_operator_value
	{
	public:

		char symbol; // A variable containing the operator symbol
		Element_operator_value* next;

		// Constructor of the element_operator_value class
		Element_operator_value(char symbol = 'O', Element_operator_value* next = nullptr)
		{
			this->symbol = symbol;
			this->next = next;
		};
		// Destructor of the element_operator_value class
		~Element_operator_value()
		{
			symbol = ' ';
			next = nullptr;
		};

	};

	Element_operator_value* head; // Pointer to the first character of the operator value
	Element_operator_value* tail; // Pointer of the last character of the operator value

public:

	// Constructor of the Element_mathematical_expression class
	Element_mathematical_expression(double digit_or_priority = -1, Element_mathematical_expression* next = nullptr)
	{
		this->digit_or_priority = digit_or_priority;
		this->next = next;
		head = nullptr;
		tail = nullptr;
	};
	// Destructor of the Element_mathematical_expression class
	~Element_mathematical_expression()
	{
		digit_or_priority = 0;
		next = nullptr;
		clear_operator_value();
		head = nullptr;
		tail = nullptr;
	};

	// Setting the digit value or priority
	void set_digit_or_priority_value(double digit_or_priority_value)
	{
		digit_or_priority = digit_or_priority_value;
	};

	// Setting the value of the operator
	void set_operator_value(char value)
	{
		Element_operator_value *current_element = new Element_operator_value(value);
		if (head == nullptr) 
		{
			head = current_element;
			tail = current_element;
		}
		else 
		{
			tail->next = current_element;
			tail = current_element;
		}
	};

	// Getting the value of a digit or the priority of an element
	double get_digit_or_priority_value(Element_mathematical_expression* current)
	{
		return current->digit_or_priority;
	}

	// Getting the operator value
	string get_operator_value(Element_mathematical_expression* current)
	{
		Element_operator_value* current_element = current->head;
		string operator_value;
		while (current_element != nullptr)
		{
			operator_value = operator_value + current_element->symbol;
			current_element = current_element->next;
		}
		return operator_value;
	};

	// Clearing the operator value
	void clear_operator_value() 
	{
		if (head != nullptr) 
		{
			while (head != nullptr) 
			{
				Element_operator_value* delete_element;
				delete_element = head;
				head = head->next;
				delete delete_element;
			}
		}		
	}
};

// Class stack
class Stack
{
	// class stack element
	class Stack_element
	{
	public:

		Element_mathematical_expression* data; // A variable containing the value of a mathematical expression
		Stack_element* next; 

		// Constructor of the stack_element class
		Stack_element(Element_mathematical_expression* data = nullptr, Stack_element* next = nullptr)
		{
			this->data = data;
			this->next = next;
		};
		// Destructor of the stack_element class
		~Stack_element()
		{
			data = nullptr;
			next = nullptr;
		}
	};

	Stack_element* head; // Pointer to the initial element of the stack
	size_t size_stack; // Stack size

public:

	// Constructor of the stack class
	Stack()
	{
		head = nullptr;
		size_stack = 0;
	};
	// Destructor of the stack class
	~Stack()
	{
		clear_stack();
		head = nullptr;
		size_stack = 0;
	};

	// Checking the stack for emptiness
	bool stack_is_empty()
	{
		return size_stack == 0;
	};

	// Getting the stack size
	int get_size_stack()
	{
		return size_stack;
	};

	// Getting the data value of a stack element
	Element_mathematical_expression* get_data_element_stack()
	{
		Stack_element* element = head;
		return head->data;
	}

	// Adding an element to the top of the stack
	void push(Element_mathematical_expression* data)
	{
		Stack_element* new_element = new Stack_element(data);
		if (stack_is_empty())
		{
			head = new_element;
			size_stack++;
		}
		else
		{
			new_element->next = head;
			head = new_element;
			size_stack++;
		}
	};

	// Adding a new stack element with the specified data
	void adding_new_data(double data)
	{
		Element_mathematical_expression* element = new Element_mathematical_expression(data);
		Stack_element* new_element = new Stack_element(element);
		if (stack_is_empty())
		{
			head = new_element;
			size_stack++;
		}
		else
		{
			new_element->next = head;
			head = new_element;
			size_stack++;
		}
	}

	// Removing an element of a mathematical expression from the stack
	Element_mathematical_expression* pop()
	{
		if (!stack_is_empty())
		{
			Element_mathematical_expression* element;
			Stack_element* delete_element;
			if (get_size_stack() == 1)
			{
				element = head->data;
				delete head;
				head = nullptr;
				size_stack = 0;
				return element;
			}
			else
			{
				element = head->data;
				delete_element = head;
				head = head->next;
				delete delete_element;
				size_stack--;
				return element;
			}
		}
		else return nullptr;
	};

	// Clearing the stack
	void clear_stack() 
	{
		if (!stack_is_empty())
		{
			while (!stack_is_empty())
			{
				pop();
			}
			head = nullptr;
			size_stack = 0;
		}
	};
};

// Class queue 
class Queue
{
	// Class queue element
	class Queue_element
	{
	public:

		Element_mathematical_expression* data; // Pointer to an element of a mathematical expression
		Queue_element* next; 

		// Constructor of the queue element class
		Queue_element(Element_mathematical_expression* data = nullptr, Queue_element* next = nullptr)
		{
			this->data = data;
			this->next = next;
		}
		// Destructor of the queue element class
		~Queue_element()
		{
			data = nullptr;
			next = nullptr;
		}
	};

	Queue_element* head; // Pointer to the beginning of the queue
	Queue_element* tail; // Pointer to the end of the queue
	size_t size_queue; // Queue size

public:

	// Constructor of the queue class
	Queue()
	{
		head = nullptr;
		tail = nullptr;
		size_queue = 0;
	};
	// Destructor of the queue class
	~Queue()
	{
		clear_queue();
		head = nullptr;
		tail = nullptr;
		size_queue = 0;
	};

	// Checking the queue for emptiness
	bool queue_is_empty()
	{
		return (queue_size() == 0);
	};

	// Getting the queue size
	size_t queue_size()
	{
		return size_queue;
	};

	// Adding an element to the end of the queue
	void enqueue(Element_mathematical_expression* data)
	{
		Queue_element* current = new Queue_element(data);
		if (queue_is_empty())
		{
			head = current;
			tail = current;
			size_queue++;
		}
		else
		{
			tail->next = current;
			tail = current;
			size_queue++;
		}
	};

	// Deleting an item from the beginning of the queue
	Element_mathematical_expression* dequeue() 
	{
		if (!queue_is_empty())
		{
			Element_mathematical_expression* element;
			Queue_element* delete_element;
			if (size_queue == 1)
			{
				element = head->data;
				delete head;
				head = nullptr;
				tail = nullptr;
				size_queue = 0;
				return element;
			}
			else
			{
				element = head->data;
				delete_element = head;
				head = head->next;
				delete delete_element;
				size_queue--;
				return element;
			}
		}
		else return nullptr;
	}

	// Clearing the queue
	void clear_queue()
	{
		if (!queue_is_empty())
		{
			while (!queue_is_empty())
			{
				dequeue();
			}
			head = nullptr;
			tail = nullptr;
			size_queue = 0;
		}
	}
};

// Class string mathematical expression
class String_mathematical_expression
{
	// Class element string
	class Element_string
	{
	public:

		char symbol; // Symbol of a mathematical expression
		Element_string* next;

		// Constructor of the element string class
		Element_string(char symbol = '\0', Element_string* next = nullptr)
		{
			this->symbol = symbol;
			this->next = next;
		};
		// Destructor of the element string class
		~Element_string()
		{
			symbol = '\0';
			next = nullptr;
		};
	};

	Element_string* head; // Pointer to the first element of the string
	Element_string* tail; // Pointer to the last element of the string
	size_t size_string; // String size

public:

	// Constructor of the string mathematical expression class
	String_mathematical_expression()
	{
		head = nullptr;
		tail = nullptr;
		size_string = 0;
	};
	// Destructor of the string mathematical expression class
	~String_mathematical_expression()
	{
		clear_string();
		head = nullptr;
		tail = nullptr;
		size_string = 0;
	};

	// Getting the row size
	size_t string_size()
	{
		return size_string;
	};

	// Checking the string for emptiness
	bool string_is_empty()
	{
		return (string_size() == 0);
	};

	// Adding a character to a string
	void add_symbol(char symbol)
	{
		Element_string* current = new Element_string(symbol);
		if (string_is_empty())
		{
			head = current;
			tail = current;
			size_string++;
		}
		else
		{
			tail->next = current;
			tail = current;
			size_string++;
		}
	};

	// Getting a character from a string
	char get_the_symbol()
	{
		char symbol;
		if (!string_is_empty())
		{
			Element_string* delete_element;
			if (size_string == 1)
			{
				symbol = head->symbol;
				delete head;
				head = nullptr;
				tail = nullptr;
				size_string--;
				return symbol;
			}
			else
			{
				delete_element = head;
				symbol = delete_element->symbol;
				head = head->next;
				delete delete_element;
				size_string--;
				return symbol;
			}
		}
	}

	// Clearing the string
	void clear_string()
	{
		if (!string_is_empty())
		{
			while (!string_is_empty())
			{
				get_the_symbol();
			}
			head = nullptr;
			tail = nullptr;
			size_string = 0;
		}
	}

	// Overloading the line output operator to the screen
	friend ostream& operator<<(ostream& stream, const String_mathematical_expression& string)
	{
		if (string.head != nullptr)
		{
			String_mathematical_expression::Element_string* current = string.head;
			while (current != nullptr)
			{
				stream << current->symbol;
				current = current->next;
			}
			return stream;
		}
		else throw domain_error("\nThe string of the mathematical expression is empty\n");
	};

	// Overloading the line entry operator
	friend istream& operator>>(istream& stream, String_mathematical_expression& string)
	{
		char symbol;
		cin.unsetf(ios::skipws);
		cin >> symbol;
		while (symbol == '\n' || symbol == ' ') cin >> symbol;
		while (symbol != '\n')
		{
			string.add_symbol(symbol);
			cin >> symbol;
			while (symbol == ' ') cin >> symbol;
		}
		return stream;
	};
};

Queue infix_form; // A queue that stores a mathematical expression in the infix form of a record
Queue postfix_form; // A queue that stores a mathematical expression in the postfix form of a record

// Checking whether the entered character is an available letter
bool Symbol_is_letter(char symbol)
{
	bool is_letter(false);
	const int number_of_letters = 15;
	char available_letters[number_of_letters] = "cosintglqraexp";
	int index_letter = 0;
	while (index_letter != number_of_letters && !is_letter)
	{
		if (available_letters[index_letter] == symbol)
		{
			is_letter = true;
		}
		index_letter++;
	};
	return is_letter;
}

// Checking whether the entered character is a digit
bool Symbol_is_digit(char symbol)
{
	bool is_number(false);
	const int number_of_digits = 11;
	char numbers[number_of_digits] = "0123456789";
	int index_digit = 0;
	while (index_digit != number_of_digits && !is_number)
	{
		if (numbers[index_digit] == symbol)
		{
			is_number = true;
		}
		index_digit++;
	};
	return is_number;
}

// Determining the priority
int Priority(char symbol)
{
	if (symbol == '(' || symbol == ')') return parenthesis;
	if (symbol == '+' || symbol == '-') return plus_and_minus_operator;
	if (symbol == '*' || symbol == '/') return multiplication_and_division_operator;
	if (symbol == '^') return exponentiation_operator;
	return symbol_is_not_an_operator;
}

// Checking for the presence of the entered function or constant in the list of available
char Definition_function_or_constant(Element_mathematical_expression* current)
{
	string function = current->get_operator_value(current);
	if (function == "cos") return function_cos;
	if (function == "sin") return function_sin;
	if (function == "tg") return function_tg;
	if (function == "ctg") return function_ctg;
	if (function == "ln") return function_ln;
	if (function == "log") return function_log;
	if (function == "sqrt") return function_sqrt;
	if (function == "asin") return function_asin;
	if (function == "acos") return function_acos; 
	if (function == "exp") return constant_exp;
	return unknown_function; 
}

// Checking the correctness of the entered mathematical expression
void Check_correctness_expression(String_mathematical_expression &mathematical_expression, String_mathematical_expression &string_expression, Queue& infix_form)
{
	int opening_bracket = 0, closing_bracket = 0; // Variables for storing opening and closing brackets
	size_t size_processed_string = mathematical_expression.string_size(); // Future size of the processed string
	char symbol = mathematical_expression.get_the_symbol(); // Getting a character from a string
	while (string_expression.string_size() != size_processed_string)
	{
		// If the entered symbol is an opening parenthesis
		if (symbol == '(')
		{
			// Creating and filling in an element of a mathematical expression
			Element_mathematical_expression* current = new Element_mathematical_expression();
			current->set_digit_or_priority_value(Priority(symbol));
			current->set_operator_value(symbol);
			infix_form.enqueue(current); // Adding a pointer to an item to the queue
			string_expression.add_symbol(symbol); // Adding a processed symbol to a string
			opening_bracket++;
			symbol = mathematical_expression.get_the_symbol(); // Move to the next symbol
			// The check goes on or there is an invalid symbol after the opening parenthesis
			if (Priority(symbol) != symbol_is_not_an_operator) 
			{
				if (symbol == '-') // If the next character is a unary minus, add a zero before it
				{
					// Creatingand filling an element of a mathematical expression with the value zero
					Element_mathematical_expression* unary_minus = new Element_mathematical_expression();
					unary_minus->set_digit_or_priority_value(0);
					unary_minus->set_operator_value('D');
					infix_form.enqueue(unary_minus); // Adding a pointer to an element with the value '0' for a unary minus to the queue
					string_expression.add_symbol('0'); // Adding the '0' symbol to a string
					size_processed_string++;
					// Creating and filling in an element of a mathematical expression
					Element_mathematical_expression* current = new Element_mathematical_expression();
					current->set_digit_or_priority_value(Priority(symbol));
					current->set_operator_value(symbol);
					infix_form.enqueue(current); // Adding a pointer to an item to the queue
					string_expression.add_symbol(symbol); // Adding a processed symbol to a string
					symbol = mathematical_expression.get_the_symbol(); // Move to the next symbol
				}
				else if (symbol != '(') // If the next character is an operator
				{
					throw invalid_argument("\nThe sign of the operator or the closing parenthesis cannot go immediately after the opening parenthesis\n");
				}
			}
		}
		// If the entered symbol is a letter
		else if (Symbol_is_letter(symbol))
		{
			// Creating and filling in an element of a mathematical expression
			Element_mathematical_expression* current = new Element_mathematical_expression();
			current->set_digit_or_priority_value(Priority(symbol));
			int length_function_or_constant = 4; // The maximum length of the name of the function or constant available in the calculator
			while (Symbol_is_letter(symbol) && length_function_or_constant) // Symbol-by-symbol recording of the function or constant
			{
				current->set_operator_value(symbol);
				string_expression.add_symbol(symbol); // Adding a processed symbol to a string
				length_function_or_constant--;
				symbol = mathematical_expression.get_the_symbol(); // Move to the next symbol
			}
			// If the maximum length of the name of the function or constant available in the calculator is exceeded
			if (Symbol_is_letter(symbol))
			{
				throw invalid_argument("\nYou have entered a set of incomprehensible set of letters or a function name that is too long\n");
			}
			else
			{
				infix_form.enqueue(current); // Adding a pointer to an item to the queue
				if (current->get_operator_value(current) == "pi") // If the read characters are the constant 'pi'
				{
					current->set_digit_or_priority_value(3.14);
				}
				// If the characters being read are an unknown function, constant or set of symbols
				else if (Definition_function_or_constant(current) == unknown_function)
				{
					throw invalid_argument("\nYou have entered a function that is unknown or unavailable\n");
				}
				else if (symbol != '(') // If it is a function or a constant that requires an argument
				{
					throw invalid_argument("\nDo not enter an argument for the entered function\n");
				}
			}
		}
		// If the entered symbol is a digit
		else if (Symbol_is_digit(symbol))
		{
			stringstream output;
			string digit_from_a_string;
			bool digit_zero_is_entered(false); // Variable for controlling the input of zero
			bool dot_symbol_is_entered(false); // Variable for Point input control
			// Creating and filling in an element of a mathematical expression
			Element_mathematical_expression* current = new Element_mathematical_expression();
			digit_from_a_string = digit_from_a_string + symbol; // Writing a symbol to a string for conversion to a real number
			string_expression.add_symbol(symbol); // Adding a processed symbol to a string
			if (symbol == '0') digit_zero_is_entered = true; // If zero is entered
			symbol = mathematical_expression.get_the_symbol(); // Move to the next symbol
			// Processing a real number starting from zero
			if (digit_zero_is_entered && symbol != '.' && Priority(symbol) == symbol_is_not_an_operator)
			{
				throw invalid_argument("\nAfter an integer zero, you need to put a dot or a sign of the operator\n");
			}
			else if (digit_zero_is_entered && symbol == '.')
			{
				digit_from_a_string = digit_from_a_string + symbol; // Writing a symbol to a string for conversion to a real number
				string_expression.add_symbol(symbol); // Adding a processed symbol to a string
				symbol = mathematical_expression.get_the_symbol(); // Move to the next symbol
				if (Symbol_is_digit(symbol)) 
				{
					// Writing characters to a string as long as they are digits
					while (Symbol_is_digit(symbol))
					{
						digit_from_a_string = digit_from_a_string + symbol; // Writing a symbol to a string for conversion to a real number
						string_expression.add_symbol(symbol); // Adding a processed symbol to a string
						symbol = mathematical_expression.get_the_symbol(); // Move to the next symbol
						if (symbol == '.') // Re-entering a point in a real number
						{
							throw invalid_argument("\nYou have entered an extra point in the real number\n");
						}
					}
				}
				else throw invalid_argument("\nThe real part of the number must consist of digits\n");

			}
			// Processing a real number that does not start from zero
			else if (!digit_zero_is_entered && Symbol_is_digit(symbol) || symbol == '.')
			{
				while (Symbol_is_digit(symbol) || symbol == '.') 
				{
					if (symbol == '.') 
					{
						if (dot_symbol_is_entered) // Re-entering a point in a real number
						{
							throw invalid_argument("\nYou have entered an extra point in the real number\n");
						}
						else 
						{
							digit_from_a_string = digit_from_a_string + symbol; // Writing a symbol to a string for conversion to a real number
							string_expression.add_symbol(symbol); // Adding a processed symbol to a string
							symbol = mathematical_expression.get_the_symbol(); // Move to the next symbol
							// If the character after the dot is not a digit
							if (!Symbol_is_digit(symbol))
							{
								throw invalid_argument("\nThe real part of the number must consist of digits\n");
							}
							dot_symbol_is_entered = true; // A dot was introduced
						}
					} 
					else 
					{
						digit_from_a_string = digit_from_a_string + symbol; // Writing a symbol to a string for conversion to a real number
						string_expression.add_symbol(symbol); // Adding a processed symbol to a string
						symbol = mathematical_expression.get_the_symbol(); // Move to the next symbol
					}
				}
			}
			output << digit_from_a_string;
			double digit;
			output >> digit;
			current->set_digit_or_priority_value(digit);
			current->set_operator_value('D');
			infix_form.enqueue(current);
			if (symbol == '(')
			{
				throw invalid_argument("\nOpening bracket cannot go immediately after a digit without an operator\n");
			}
			else if (Symbol_is_letter(symbol))
			{
				throw invalid_argument("\nLetter cannot go immediately after a digit without an operator\n");
			}
		}
		// If the entered symbol is an operator and not a parenthesis sign
		else if (Priority(symbol) != symbol_is_not_an_operator && Priority(symbol) != parenthesis)
		{
			if (symbol == '-' && infix_form.queue_is_empty()) // Entering a unary minus at the beginning of a mathematical expression
			{
				// Creatingand filling an element of a mathematical expression with the value zero
				Element_mathematical_expression* unary_minus = new Element_mathematical_expression();
				unary_minus->set_digit_or_priority_value(0); 
				unary_minus->set_operator_value('D');
				string_expression.add_symbol('0'); // Adding the '0' symbol to a string
				infix_form.enqueue(unary_minus); // Adding a pointer to an element with the value '0' for a unary minus to the queue
				size_processed_string++;
			}
			// If the entered mathematical expression ends with the operator
			if (mathematical_expression.string_size() == 0)
			{
				throw invalid_argument("\nA mathematical expression cannot end with an operator sign\n");
			}
			// Creating and filling in an element of a mathematical expression
			Element_mathematical_expression* current = new Element_mathematical_expression();
			current->set_digit_or_priority_value(Priority(symbol));
			current->set_operator_value(symbol);
			string_expression.add_symbol(symbol); // Adding a processed symbol to a string
			infix_form.enqueue(current); // Adding a pointer to an item to the queue
			symbol = mathematical_expression.get_the_symbol(); // Move to the next symbol
			// If the operator symbol is immediately followed by the same operator symbol
			if (Priority(symbol) != symbol_is_not_an_operator && Priority(symbol) != parenthesis)
			{
				throw invalid_argument("\nIn a mathematical expression, two operators cannot go in a row without divisions\n");
			}
			// If the operator character is immediately followed by a closing parenthesis
			else if (symbol == ')')
			{
				throw invalid_argument("\nThe symbol ')' cannot go immediately after the operator\n");
			}
		}
		// If the entered character is a closing parenthesis
		else if (symbol == ')')
		{
		    // If there are more closing brackets than opening ones
			if (closing_bracket + 1 > opening_bracket)
			{
				throw invalid_argument("\nThere cannot be more closing brackets than opening ones\n");
			}
			else
			{
				// Creating and filling in an element of a mathematical expression
				Element_mathematical_expression* current = new Element_mathematical_expression();
				current->set_digit_or_priority_value(Priority(symbol));
				current->set_operator_value(symbol);
				infix_form.enqueue(current); // Adding a pointer to an item to the queue
				string_expression.add_symbol(symbol); // Adding a processed symbol to a string
				closing_bracket++;
				symbol = mathematical_expression.get_the_symbol(); // Move to the next symbol
			}
			if (Symbol_is_letter(symbol)) // If the closing parenthesis is followed by the letter
			{
				throw invalid_argument("\nThe letter cannot go immediately after the closing parenthesis without the operator\n");
			}
			else if (Symbol_is_digit(symbol)) // If there is a digit after the closing parenthesis
			{
				throw invalid_argument("\nThe digit cannot go immediately after the closing parenthesis without the operator\n");
			}
			else if (symbol == '(') // If the closing parenthesis is followed by an opening parenthesis
			{
				throw invalid_argument("\nSymbols ')' and '(' cannot go in this sequence without the operator\n");
			}
		}
		else // If the entered character is unknown
		{
			throw invalid_argument("\nSymbols unrecognized by the program were entered\n");
		}
	}
	// If fewer opening brackets were specified than closing ones
	if (closing_bracket < opening_bracket)
	{
		throw invalid_argument("\nYou missed the closing parenthesis\n");
	}
};

// Ñonversion of the infix form of the record to the postfix form
void Conversion_to_postfix_form(Queue &infix_form, Queue &postfix_form)
{
	if (!infix_form.queue_is_empty()) // Checking the queue in which the infix form of the record is stored for emptiness
	{
		Stack stack; // Creating an empty stack to store operators
		cout << "\nPostfix form: ";
		while (!infix_form.queue_is_empty()) // While there are elements in the queue storing the infix form of the record
		{
			Element_mathematical_expression* element = new Element_mathematical_expression();
			element = infix_form.dequeue(); // Getting an element of a mathematical expression
			double digit_or_priority = element->get_digit_or_priority_value(element); // Getting a priority value or number
			string operator_value = element->get_operator_value(element); // Getting the operator value
			// If the element is an operand or constant 'pi'
			if (operator_value == "D" || operator_value == "pi")
			{
				cout << digit_or_priority << " "; // Output of the operand to the screen
				postfix_form.enqueue(element); // Adding an element containing the operand value to the pointer queue  
			}
			// If the element is an opening parenthesis
			else if (operator_value == "(")
			{
				stack.push(element); // Adding a pointer to an element to the stack
			}
			// If the element is a closing parenthesis
			else if (operator_value == ")")
			{
				// Pushing items off the stack until the corresponding left bracket is found.
				while (stack.get_data_element_stack()->get_operator_value(stack.get_data_element_stack()) != "(")
				{
					// Operator output to the screen
					cout << stack.get_data_element_stack()->get_operator_value(stack.get_data_element_stack()) << " ";
					postfix_form.enqueue(stack.pop()); // Adding a pointer to an element containing the value of the operator
				}
				stack.pop(); // 
			}
			else // If the element is an operator
			{
				// If the stack is empty
				if (!stack.stack_is_empty())
				{
					// Retrieving any of the statements already on the stack, if it has greater or equal priority.
					if (digit_or_priority <= stack.get_data_element_stack()->get_digit_or_priority_value(stack.get_data_element_stack()))
					{
						// Operator output to the screen
						cout << stack.get_data_element_stack()->get_operator_value(stack.get_data_element_stack()) << " ";
						postfix_form.enqueue(stack.pop()); // Adding a pointer to an element containing the value of the operator 
					}
				}
				stack.push(element); // Adding a pointer to an element to the stack
			}
		}
		// If the queue of infix form elements has been processed, but there are still operators left in the stack
		while (!stack.stack_is_empty())
		{
			// Operator output to the screen
			cout << stack.get_data_element_stack()->get_operator_value(stack.get_data_element_stack()) << " ";
			postfix_form.enqueue(stack.pop()); // Adding a pointer to an element containing the value of the operator 
		}
	}
	else throw domain_error("\nThere is no mathematical expression in the infix\n");
};

// Calculating the function value
double Calculating_the_function_value(char type_of_function, double function_argument)
{
	double function_value = 0; // A variable storing a value for a function
	if (type_of_function == function_cos) return function_value = cos(function_argument);
	if (type_of_function == function_sin) return function_value = sin(function_argument);
	if (type_of_function == function_tg) return function_value = tan(function_argument);
	if (type_of_function == function_ctg) return function_value = 1 / tan(function_argument);
	if (type_of_function == function_ln) return function_value = log(function_argument);
	if (type_of_function == function_log) return function_value = log10(function_argument);
	if (type_of_function == function_sqrt) return function_value = sqrt(function_argument);
	if (type_of_function == function_asin) return function_value = asin(function_argument);
	if (type_of_function == function_acos) return function_value = acos(function_argument);
	if (type_of_function == constant_exp) return function_value = exp(function_argument);
}

// The product of an arithmetic operation
double Arithmetic_operation(string operation, double first_argument, double second_argument)
{
	double result_arithmetic_operation = 0; // A variable that stores the result of an arithmetic operation
	if (operation[0] == '+') return result_arithmetic_operation = (first_argument + second_argument);
	if (operation[0] == '-') return result_arithmetic_operation = (first_argument - second_argument);
	if (operation[0] == '*') return result_arithmetic_operation = (first_argument * second_argument);
	if (operation[0] == '/') return result_arithmetic_operation = (first_argument / second_argument);
	if (operation[0] == '^') return result_arithmetic_operation = (pow(first_argument, second_argument));
}

// Calculating the value of the entered mathematical expression
double Calculating_the_value(Queue &postfix_form)
{
	double result = 0; // A variable that stores the result of a mathematical expression
	Stack stack; // Creating an empty stack
	if (!postfix_form.queue_is_empty()) 
	{
		// While the queue of the postfix form of the record is not empty
		while (!postfix_form.queue_is_empty())
		{
			Element_mathematical_expression* element = new Element_mathematical_expression();
			element = postfix_form.dequeue(); // Getting an element of a mathematical expression
			double digit_or_priority = element->get_digit_or_priority_value(element); // Getting a priority value or number
			string operator_value = element->get_operator_value(element); // Getting the operator value
			// If the element is an operand or constant 'pi'
			if (operator_value == "D" || operator_value == "pi")
			{
				stack.push(element); // Adding a pointer to an element to the stack
			}
			else
			{
				// If the operator is not a function and the stack is not empty
				if (Definition_function_or_constant(element) == unknown_function && !stack.stack_is_empty())
				{
					Element_mathematical_expression* data_second_operand = stack.pop(); // Pushing the second operand off the stack
					double second_operand = data_second_operand->get_digit_or_priority_value(data_second_operand);
					if (!stack.stack_is_empty())
					{
						Element_mathematical_expression* data_first_operand = stack.pop(); // Pushing the first operand off the stack
						double first_operand = data_first_operand->get_digit_or_priority_value(data_first_operand);
						result = Arithmetic_operation(operator_value, first_operand, second_operand); // Performing an arithmetic operation
						stack.adding_new_data(result); // Putting the result of an arithmetic operation back on the stack
					}
				}
				// If the operator is a functionand the stack is not empty
				else if (!stack.stack_is_empty())
				{
					Element_mathematical_expression* operand = stack.pop(); // Pushing an operand off the stack
					// Calculating the function value
					result = Calculating_the_function_value(Definition_function_or_constant(element), operand->get_digit_or_priority_value(operand));
					stack.adding_new_data(result); // Putting the result of an arithmetic operation back on the stack
				}
			}
		}
		return result; // Returning the result of calculating a mathematical expression
	}
	else throw domain_error("\nThe queue with the postfix form of the mathematical expression is empty\n");
}

// Processing a mathematical expression
double Processing_mathematical_expression(String_mathematical_expression &mathematical_expression)
{
	String_mathematical_expression string_expression; // A string that will store the string entered by the user after verification
	try
	{
		// Checking the correctness of the entered mathematical expression
		Check_correctness_expression(mathematical_expression, string_expression, infix_form);
		// Output of a mathematical expression in infix form to the screen
		cout << "\nInfix_form: " << string_expression;
	}
	catch (const domain_error error)
	{
		cout << error.what();
		return 2;
	}
	catch (const invalid_argument error)
	{
		cout << '\n' << error.what();
		// Specifying the position of incorrect input
		if (!string_expression.string_is_empty())
		{
			cout << "Location of the error: " << string_expression << '\n';
		}
		else cout << "Location of the error: the first symbol\n";
		return 1;
	}
	try
	{
		// Ñonversion of the infix form of the record to the postfix form
		Conversion_to_postfix_form(infix_form, postfix_form);
		// Displaying the result of calculating a mathematical expression
		cout << "\nThe meaning of a mathematical expression: ";
		cout << Calculating_the_value(postfix_form) << '\n';
	}
	catch (const domain_error error)
	{
		cout << '\n' << error.what();
		return 3;
	}
	return 0;
}