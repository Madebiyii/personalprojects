#!/usr/bin/env sh

# Ensure no class files are present
unzip -l JavaSoc.zip | grep -E "\.class" > /dev/null
if [ $? -eq 0 ]; then
    echo "Class files should not be present in submission";
    exit 1;
fi

# Ensure demo.txt is present
unzip -l JavaSoc.zip | grep "demo.txt" > /dev/null
if [ $? -ne 0 ]; then
    echo "demo.txt not present in submission";
    exit 1;
fi

# Ensure report.txt is present
unzip -l JavaSoc.zip | grep "report.txt" > /dev/null
if [ $? -ne 0 ]; then
    echo "report.txt not present in submission";
    exit 1;
fi

# Ensure ClientApp.java is present
unzip -l JavaSoc.zip | grep "ClientApp.java" > /dev/null
if [ $? -ne 0 ]; then
    echo "ClientApp.java not present in submission";
    exit 1;
fi

# Unzip and extract contents
unzip -o JavaSoc.zip > /dev/null

# Compile everything
javac *.java
if [ $? -ne 0 ]; then
    echo "Compiler error. Code is incorrect or zipped files are in a folder";
    exit 1;
fi

# Execute Test -> ClientApp.demo()
java JavaSoc > output.txt
if [ $? -ne 0 ]; then
    echo "Runtime error";
    exit 1;
fi

# check output.txt and demo.txt match
diff --strip-trailing-cr output.txt demo.txt
if [ $? -ne 0 ]; then
    echo "Code output and demo.txt do not match";
    exit 1;
fi

# check report.txt is within word limit
REPORT=$(cat report.txt | wc -w)
WORDLIMIT=600
if [ $REPORT -ge $WORDLIMIT ]; then
    echo "report.txt should be within 500 words";
    exit 1;
fi

echo "success"