#! /bin/bash


buildpath=""
currentpath=""
execpath=""
repopath=""

main() {
echo "mortsgna build setup"
echo "#####################"
currentpath=$(dirname $(realpath $0))
execpath=$(pwd)



read -p "Enter your build path: " buildpath

setPathEnv
showConfig

$currentpath/applypatches.sh
cd $execpath

echo "Do the following steps to build:"
echo "1. Go to the oe-core folder"
echo "2. call source ../.oe/environment-oecore.sh"
echo "3. Build the image. (e.g. bitbake com5003-mt310s2-image)"
}


setBuildFolderInConfig() {

echo "test"

}

setPathEnv() {
cd $currentpath
cd ..
repopath=$(pwd)
text="$repopath/oe-core/sources/openembedded-core/scripts:$repopath"'/oe-core/sources/bitbake/bin:$PATH'
cd .oe
rm environment-oecore.sh
echo "export PATH=\"$text\"" > environment-oecore.sh
cd $execpath
}

showConfig() {
echo "current configuration"
echo "#####################"
echo "currentpath:" $currentpath
echo "execpath:" $execpath
echo "buildpath:" $buildpath
echo "bitbake path " $repopath'/oe-core/sources/bitbake/bin'
}


main
exit 0
