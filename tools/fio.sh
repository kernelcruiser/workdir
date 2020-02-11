fio -direct=0 -iodepth=128 -rw=randwrite -ioengine=libaio -bs=4k -size=1000G -numjobs=4 -runtime=600000 -group_reporting -name=Rand_Write_Testing -filename=./4k_test&
