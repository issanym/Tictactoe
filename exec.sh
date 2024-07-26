
#!/bin/bash

# Get the directory where the script is located
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Get the parent directory name
PARENT_DIR="$(basename "$SCRIPT_DIR")"

# Define the path to the executable
EXECUTABLE_PATH="$SCRIPT_DIR/bin/$PARENT_DIR"

# Check if the executable exists
if [ ! -f "$EXECUTABLE_PATH" ]; then
  echo "Executable $EXECUTABLE_PATH not found!"
  exit 1
fi

# Open a new terminal window and run the executable
gnome-terminal -- "$EXECUTABLE_PATH"
