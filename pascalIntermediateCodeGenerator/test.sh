# This shell script is to make the testing easy

if [[ $# != 1 ]]; then
    echo "Usage: $0 <program_number>";
    exit 1;
fi

make;

# Open the error free file
if [[ $1 == 2 ]]; then
	./parser < trial.pas
fi

# Open the erroneous file
if [[ $1 == 1 ]]; then
	./parser < trialerrors.pas
fi
