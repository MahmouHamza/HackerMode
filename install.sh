# Remove old version from the tool.
rm -rif HackerMode ~/.HackerMode ~/../usr/bin/HackerMode &>/dev/null
rm -f HackerModeInstall &>/dev/null
rm -rif PSHMode ~/.PSHMode ~/../usr/bin/PSHMode &>/dev/null
rm -f PSHMode.install &>/dev/null

# Get the platform.
PLATFORM=$(python3 -c "import sys,os;print('win' if sys.platform in ('win32', 'cygwin') else 'macosx' if sys.platform == 'darwin' else 'termux' if os.environ.get('PREFIX') != None else 'linux' if sys.platform.startswith('linux') or sys.platform.startswith('freebsd') else 'unknown')")

# PSHMode logs
LOG_FILE=".PSHMode-install.log"

# To install before setup the tool.
PSHMODE_PACKAGES='wget git unzip zip'

# Download PSHMode and move it to home.
function download_PSHMode() {
  cd $HOME
  rm -f main.zip
  wget https://github.com/Arab-developers/PSHMode/archive/refs/heads/main.zip &>> $LOG_FILE
  unzip main.zip &>/dev/null
  rm -f main.zip
  mv -f PSHMode-main .PSHMode
}

if [[ $PLATFORM != "unknown" ]]; then
  echo -e "\n\nStart installing for ( \033[1;32m$PLATFORM\033[0m )"
fi

# Linux installation...
if [[ $PLATFORM == "linux" ]]; then
  # Install packages...
  sudo apt update -y
  sudo apt install $PSHMODE_PACKAGES -y &>> $LOG_FILE
  sudo apt install python3 -y &>> $LOG_FILE
  sudo apt install python3-pip -y &>> $LOG_FILE

  # Download the tool.
  download_PSHMode
  sudo python3 -B .PSHMode add_shortcut
  python3 -B .PSHMode install

# Termux installation...
elif [[ $PLATFORM == "termux" ]]; then
  # Install packages...
  pkg update -y
  pkg install $PSHMODE_PACKAGES -y &>> $LOG_FILE

  # Get sdcard permission.
  ls /sdcard &>> $LOG_FILE || termux-setup-storage

  # Download the tool.
  download_PSHMode
  python3 -B .PSHMode add_shortcut
  mkdir /sdcard/PSHMode &>> $LOG_FILE
  python3 -B .PSHMode install

fi

# Remove variables from the global namespace.
unset PLATFORM PSHMODE_PACKAGES LOG_FILE
unset -f download_PSHMode

# Add PSHMode command line.
source $HOME/.PSHMode/PSHMode.shortcut
