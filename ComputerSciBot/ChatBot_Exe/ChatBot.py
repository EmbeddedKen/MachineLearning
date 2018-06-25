import sys
if (sys.version_info.major != 3 and sys.version_info.minor != 6):
    raw_input("Need to Use Python 3.6! Try Again! Exiting...")
    exit()

from chatterbot import ChatBot
from chatterbot.trainers import ListTrainer

#Initialize ChatBot According to ChatterBot List Standards
chatbot = ChatBot("CompSciBot")
chatbot.set_trainer(ListTrainer)
#Train Chat-Bot with Q&A Data
'''
chatbot.train([
    "What is a Stack Overflow?",
    "A Stack Overflow occurs when too much memory has been placed on the call stack.",
    "Why do I have a Stack Overflow?",
    "You likely used an infinitly-recursive function.",
    
    "What is a Linker Error?"
    "A Linker Error occurs when an external or internal dependency was not found for linkage",
    "Why do I have a Linker Error?",
    "Linker Errors occur for a number of reasons, sometimes it is improper syntax. Potentially there are defined, yet unimplemented functions.",
    
    "What is a Function?",
    "A Function is a named block of code (subroutine) that one executes by calling (jumping with arguments) to."

    "What is a Macro?",
    "A Macro named symbol that represents an expression or set of statements that are expanded at compile-time by the preprocessor.",

    "What is a Pointer?",
    "A Pointer is a variable that stores the address of another piece of memory. It points to somewhere else.",

    "What is a Variable?",
    "A Variable is a symbol that represents a memory address and fixed allocation unit contiuing past the start address.",

    "What is an Integer?",
    "An Integer is a whole, real-number; with varying definitions of length depending on the system bus-width.",

    "What is a Floating-Point?",
    "A Floating-Point is a unit that represents base-ten fractional decimals. It is called Floating-Point, because the point floats with the mantissa.",

    "What is a Double?",
    "A Double is a unit that represents base-ten fractional decimals. It is approximately double the length of whatever floating-points are defined on the system.",

    "What is a String?",
    "A String is an array of contigous integers that represent ASCII or Unicode characters.",

    "What is a Compiler?",
    "A Compiler is a program that converts high-level programming language source code into assembly. Some compilers also include assembler, and linkage steps.",

    "What is an Assembler?",
    "An Assembler is a program that converts assembly source code into machine code. It represents non-portable code, since it is machine-dependent.",

    "What is Assembly?",
    "Assembly is a human-readable form of machine code following a certain Instruction Set Architecture (ISA). It is not portable to other ISAs." ,

    "What is an Object File?",
    "An Object File is an array of executable instructions and data, that represent an individual source-code file in binary. Often times multiple are linked together to form an executable or ELF-image.",

    "What is an Executable?",
    "An Executable is a binary file that represents a computer program that is compliant with the System's Application Binary Interface (ABI), and contains a header and symbol table.",

    "What is a Header File?",
    "A Header File contains definitions and sometimes implementations of functions and/or classes. Header Files are expanded during compile-time by the preprocessor.",
    
    "What is OOP?",
    "Object-Oriented Programming is an abstraction of data and functions (classes) that allow for instance-based programming (objects).",
])
'''

# Initial Program Greeting
print("[READY]")								#Signify on StandardOutputStream that Bot is Ready
print("Hello, I am Computer Science Bot! Ask me anything!")
# Provide ChatBot Response Per User Input
while (True):
    userInput = input("")                  		#Get ChatBot Response from StandardInputStream
    response = chatbot.get_response(userInput)  #"
    print(response)                     		#Display ChatBot Result to StandardOutputStream
