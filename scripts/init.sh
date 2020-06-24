#! /bin/sh


buildpath=""
currentpath=""
execpath=""
repopath=""
applyPatch=""

main() {
echo "mortsgna build setup"
echo "#####################"
currentpath=$(dirname $(realpath $0))
execpath=$(pwd)

while [ "$buildpath" == "" ]
do
	read -p "Enter your build path: " buildpath
done

setPathEnv
setBuildFolderInConfig
showConfig

while [ "$applyPatch" != "yes" ] && [ "$applyPatch" != "no" ]
do
	read -p "Do you want to apply patches?(yes/no)" applyPatch
done

if [ $applyPatch == "yes" ] ; then
	$currentpath/applypatches.sh	
fi

cd $execpath

echo "Do the following steps to build:"
echo "1. Go to the oe-core folder"
echo "2. call source ../.oe/environment-oecore.sh"
echo "3. Build the image. (e.g. bitbake com5003-mt310s2-image)"
}


setBuildFolderInConfig() {
cd $currentpath
cd ../oe-core/conf/
sed -i -e 's/TMPDIR = ".*"/TMPDIR = '"\"$buildpath\""'/g' local.conf
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

while getopts "p:b:h" arg; do
  case $arg in
    h)
      echo "usage" 
      ;;
    b)
      buildpath=$OPTARG
      ;;
    p)
      applyPatch=$OPTARG
      ;;
  esac
done


main
exit 0
