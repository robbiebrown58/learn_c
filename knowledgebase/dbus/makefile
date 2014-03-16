#sudo apt-get -y install dbus libdbus-1-dev libdbus-glib-1-2 libdbus-glib-1-dev

example:
	gcc -std=c99 -I/usr/include/dbus-1.0 \
                     -I/usr/lib/x86_64-linux-gnu/dbus-1.0/include \
                     -I/usr/include/glib-2.0 \
		     -I/usr/lib/x86_64-linux-gnu/glib-2.0/include \
                     example.c -ldbus-1 -ldbus-glib-1 -lgobject-2.0 -o example.out

example1:
	gcc -std=c99 -I/usr/include/dbus-1.0 \
                     -I/usr/lib/x86_64-linux-gnu/dbus-1.0/include \
                     -I/usr/include/glib-2.0 \
		     -I/usr/lib/x86_64-linux-gnu/glib-2.0/include \
                     dbus-example-1.c -ldbus-1 -ldbus-glib-1 -lgobject-2.0 -o example1.out

daemon:
	gcc -std=c99 -I/usr/include/dbus-1.0 \
                     -I/usr/lib/x86_64-linux-gnu/dbus-1.0/include \
                     -I/usr/include/glib-2.0 \
		     -I/usr/lib/x86_64-linux-gnu/glib-2.0/include \
                     dbus-daemon.c -ldbus-1 -ldbus-glib-1 -lgobject-2.0 -o daemon.out


clean:
	rm *.out *~
