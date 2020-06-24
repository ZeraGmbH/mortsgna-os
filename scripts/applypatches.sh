#! /bin/bash

#First put your patch into the folder patches. Then call the patch command here.
#But Attention to patch a layer is not recommended. Before you do that consider 
#source code patches or a custom branch.

execpath=""
currentpath=""
patchpath=""

openembeddedcore(){

echo "test"
git am $patchpath/0001-u-boot-introduce-UBOOT_INITIAL_ENV.patch
}





patchlist() {
cd ../oe-core/sources/openembedded-core
openembeddedcore
cd $currentpath




}



main() {
echo "strating to patch layers"
execpath=$(pwd)
currentpath=$(dirname $(realpath $0))
cd $currentpath
cd ..
cd patches
patchpath=$(pwd)
cd $currentpath
patchlist
cd $execpath
echo "finished patching"
}

main
exit 0
