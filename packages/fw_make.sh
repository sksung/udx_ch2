#!/bin/bash

app_name="D16"
FILE="fw_version.txt"

# run make fw 

function print_fw_num()
{
 echo
 echo -------------------
 echo  Firmware model
 echo -------------------
 echo " 1 - D16 Global"
 echo " 2 - D16 HTRV"
 echo " 3 - D16 ATVS"
 echo " 4 - DTC Bike"
 echo " 5 - DTC Drive"
 echo " 6 - DTC Train"
 echo " 7 - CWX 2ch"
 echo " 8 - PLUTO 2ch"
 echo " 0 - exit"
 echo -------------------
 echo
}

function make_app_name()
{
  case "$1" in
    "1"  ) app_name="D16";;
    "2"  ) app_name="HTRV";;
    "3"  ) app_name="ATVS";;
    "4"  ) app_name="DB";;
    "5"  ) app_name="DD";;
    "6"  ) app_name="DT";;
    "7"  ) app_name="CW";;
    "8"  ) app_name="PB";;    
  esac
}

# write to fw_version.txt
function fwrite()
{
/bin/cat <<EOM >$FILE
TYPE	$1
MODEL	$app_name
MAJOR	$2
MINOR	$3
PATCH	$4
CTAG	$5
EOM

echo
echo Write to $FILE: "$app_name"_$2.$3.$4$5-$1 
}


function compile_ubifs()
{
	echo	
	echo "------------------------------------------"
	echo      Compile "$fw_name" ubifs...
	echo "------------------------------------------"	

  echo
  echo "Owner Setting TARGET Directory To "$USER" ..."
	sudo chown -Rf "$USER" ../target

	echo
  echo "Making UBIFS ..."	
	make -s ubifs
}


# Input F/W model number...

while [ "$fw_num" != "0" ]
do

 print_fw_num
 
 echo -n "Select Number(0~7): "
 read fw_num

 if [ "$fw_num" -ge "1"  ] && [ "$fw_num" -le "7"  ]
 then
   make_app_name "$fw_num"

   echo
   echo -n "Input the $app_name version(ex 1.02.03.T): "
   read ver0

   # parsing input version...
   ver1=$(echo $ver0 | cut -d '.' -f1)
   ver2=$(echo $ver0 | cut -d '.' -f2)
   ver3=$(echo $ver0 | cut -d '.' -f3)
   ver4=$(echo $ver0 | cut -d '.' -f4)
   ver4=$(echo "$ver4" | tr '[:lower:]' '[:upper:]')
   fw_name=""$app_name"_$ver1.$ver2.$ver3$ver4"   

   echo
   echo -n "Update micom binary to device? (y/n): "
   read micom

   if [ "$micom" == "y" ] || [ "$micom" == "Y" ] 
   then
     micom=1
   else
     micom=0
   fi   
   
   echo
   echo -n "MAKE THE FIRMWARE "$fw_name" Right? (y/n): " 
   read yn

   if [ "$yn" == "y" ] || [ "$yn" == "Y" ] 
   then
     break;
   fi
 fi
 
done

if [ "$fw_num" == "0" ] 
then
  echo "FW Manager eixt..."
  echo
  exit 0
fi


# make ubifs
compile_ubifs


# move build directory
cd build


echo
echo
echo
fwrite "debug" "$ver1" "$ver2" "$ver3" "$ver4"

if [ "$micom" == "1" ] 
then
	echo "---------------------------------------------"
	echo Archiving "$fw_name"_MICOM_psp_F.app for DEBUG...
	echo "---------------------------------------------"
   tar cvf "$fw_name"_MICOM_psp_F.app boot.scr fw_version.txt mcu_hd2.txt MLO rfs_hd2.ubifs u-boot_hd2.bin u-boot_hd2.min.nand uImage_hd2
else
	echo "---------------------------------------------"
	echo Archiving "$fw_name"_psp_F.app for DEBUG...
	echo "---------------------------------------------"
   tar cvf "$fw_name"_psp_F.app boot.scr fw_version.txt MLO rfs_hd2.ubifs u-boot_hd2.bin u-boot_hd2.min.nand uImage_hd2
fi


echo
echo
echo
fwrite "release" "$ver1" "$ver2" "$ver3" "$ver4"

if [ "$micom" == "1" ]
then
	echo "---------------------------------------------"
	echo Archiving "$fw_name"_MICOM_psp.app for RELEASE...
	echo "---------------------------------------------"
   tar cvf "$fw_name"_MICOM_psp.app boot.scr fw_version.txt mcu_hd2.txt MLO rfs_hd2.ubifs u-boot_hd2.bin u-boot_hd2.min.nand uImage_hd2
else
	echo "---------------------------------------------"
	echo Archiving "$fw_name"_psp.app for RELEASE...
	echo "---------------------------------------------"
   tar cvf "$fw_name"_psp.app boot.scr fw_version.txt MLO rfs_hd2.ubifs u-boot_hd2.bin u-boot_hd2.min.nand uImage_hd2
fi

mv *.app release/.

echo
echo
echo
echo Firmware make done...
echo


