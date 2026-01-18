#!/bin/bash

# Colors
YELLOW='\033[1;33m'
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Bold text
BOLD="\e[1m"
NORMAL="\e[0m"

# Compile the project
make

echo ""
# Test cases
echo -e "${YELLOW}Test 1 - Source file does not exist${NC}"
echo -e "${BOLD}./loser_sed non_existent.txt hello world${NORMAL}"
./loser_sed non_existent.txt hello world
if [ $? -ne 1 ]; then
    echo -e "${RED}Test failed: Program did not return an error${NC}"
else
    echo -e "${GREEN}Test passed${NC}"
fi
echo ""

echo -e "${YELLOW}Test 2 - File without read permissions${NC}"
echo "echo \"hello hello hello\" > test1.txt"
echo "hello hello hello" > test1.txt
echo "chmod -r test1.txt"
chmod -r test1.txt
echo -e "${BOLD}./loser_sed test1.txt hello world${NORMAL}"
./loser_sed test1.txt hello world
if [ $? -ne 1 ]; then
    echo -e "${RED}Test failed: Program did not return an error${NC}"
else
    echo -e "${GREEN}Test passed${NC}"
fi
chmod +r test1.txt
rm -f test1.txt
echo ""

echo -e "${YELLOW}Test 3 - s1 is empty${NC}"
echo "echo \"hello hello hello\" > test1.txt"
echo "hello hello hello" > test1.txt
echo -e "${BOLD}./loser_sed test1.txt \"\" world${NORMAL}"
./loser_sed test1.txt "" world
if [ $? -ne 1 ]; then
    echo -e "${RED}Test failed: Program did not return an error${NC}"
else
    echo -e "${GREEN}Test passed${NC}"
fi
rm -f test1.txt
echo ""

echo -e "${YELLOW}Test 4 - No arguments${NC}"
echo -e "${BOLD}./loser_sed${NORMAL}"
./loser_sed
if [ $? -ne 1 ]; then
    echo -e "${RED}Test failed: Program did not return an error${NC}"
else
    echo -e "${GREEN}Test passed${NC}"
fi
echo ""

echo -e "${YELLOW}Test 5 - Not enough arguments${NC}"
echo -e "${BOLD}./loser_sed test1.txt hello${NORMAL}"
./loser_sed test1.txt hello
if [ $? -ne 1 ]; then
    echo -e "${RED}Test failed: Program did not return an error${NC}"
else
    echo -e "${GREEN}Test passed${NC}"
fi
echo ""

echo -e "${YELLOW}Test 6 - Source file is empty${NC}"
echo "touch test1.txt"
touch test1.txt
echo -e "${BOLD}./loser_sed test1.txt hello world${NORMAL}"
./loser_sed test1.txt hello world
if [ $? -ne 1 ]; then
    echo -e "${RED}Test failed: Program did not return an error${NC}"
else
    echo -e "${GREEN}Test passed${NC}"
fi
rm -f test1.txt
echo ""

echo -e "${YELLOW}Test 7 - Output file cannot be created${NC}"
echo -e "${BOLD}./loser_sed test1.txt hello world${NORMAL}"
echo "hello hello hello" > test1.txt
echo "mkdir test1.txt.replace"
mkdir test1.txt.replace
./loser_sed test1.txt hello world
if [ $? -ne 1 ]; then
    echo -e "${RED}Test failed: Program did not return an error${NC}"
else
    echo -e "${GREEN}Test passed${NC}"
fi
rm -rf test1.txt.replace
rm -f test1.txt
echo ""

echo -e "${YELLOW}Test 8 - Normal replacement${NC}"
echo "echo \"hello hello hello\" > test1.txt"
echo "hello hello hello" > test1.txt
echo -e "${BOLD}./loser_sed test1.txt hello world${NORMAL}"
./loser_sed test1.txt hello world
output_file="test1.txt.replace"
if [ -f "$output_file" ]; then
    echo -e "${GREEN}Output file $output_file created successfully.${NC}"
    echo -n "Content of $output_file: " && cat "$output_file"
else
    echo -e "${RED}Failed to create output file $output_file.${NC}"
fi
rm -f test1.txt $output_file
echo ""

# Clean up
# make fclean