KERN_DIR = /home/angin/work/ok6410/linux-3.0.1

all:
	make -C $(KERN_DIR) M=`pwd` modules 

clean:
	make -C $(KERN_DIR) M=`pwd` modules clean
	rm -rf modules.order

obj-m	+= at24cxx.o
obj-m   += client.o
