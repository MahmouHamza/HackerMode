# Remove old version from the tool.
rm -rif HackerMode ~/.HackerMode ~/../usr/bin/HackerMode &>/dev/null
rm -f HackerModeInstall &>/dev/null
rm -rif PSHMode ~/.PSHMode ~/../usr/bin/PSHMode &>/dev/null
rm -f PSHMode.install &>/dev/null

# get the platform.
PLATFORM=$(python3 -c "import sys,os;print('win' if sys.platform in ('win32', 'cygwin') else 'macosx' if sys.platform == 'darwin' else 'termux' if os.environ.get('PREFIX') != None else 'linux' if sys.platform.startswith('linux') or sys.platform.startswith('freebsd') else 'unknown')")

# To install before setup the tool.
PSHMODE_PACKAGES='wget git unzip zip'

# Download PSHMode and move it to home.
function download_PSHMode() {
  cd $HOME
  rm -f main.zip
  wget https://github.com/Arab-developers/PSHMode/archive/refs/heads/main.zip
  unzip main.zip &>/dev/null
  rm -f main.zip
  mv -f PSHMode-main .PSHMode
}

# linux installation...
if [[ "$PLATFORME" -eq "linux" ]]; then
  # install packages...
  sudo apt update -y
  sudo apt install $PSHMODE_PACKAGES -y
  sudo apt install python3 -y
  sudo apt install python3-pip -y

  # download the tool.
  download_PSHMode
  sudo python3 -B .PSHMode add_shortcut
  python3 -B .PSHMode install

elif [[ "$PLATFORME" -eq "termux" ]]; then
  # install packages...
  pkg update -y
  pkg install $PSHMODE_PACKAGES -y

  # get sdcard permission.
  ls /sdcard &>/dev/null || termux-setup-storage

  # download the tool.
  download_PSHMode
  sudo python3 -B .PSHMode add_shortcut
  mkdir /sdcard/PSHMode <&/dev/null
  python3 -B .PSHMode install

fi

# Remove variables from the global namespace.
unset PLATFORM PSHMODE_PACKAGES
unset -f download_PSHMode

# add PSHMode command line.
function PSHMode() {
  if [ $1 ]; then
    if [ $1 == "check" ]; then
      $HOME/.PSHMode/bin/PSHMode check
    elif [ $1 == "update" ]; then
      $HOME/.PSHMode/bin/PSHMode update
    elif [ $1 == "delete" ]; then
      $HOME/.PSHMode/bin/PSHMode delete
    else
      $HOME/.PSHMode/bin/PSHMode --help
    fi
  else
    if [ $VIRTUAL_ENV ]; then
      echo "PSHMode is active."
    else
      source $HOME/.PSHMode/bin/activate
    fi
  fi
}