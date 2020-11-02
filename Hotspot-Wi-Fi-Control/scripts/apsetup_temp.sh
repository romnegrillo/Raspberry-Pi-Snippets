#!/bin/bash

cat > /etc/dnsmasq.conf <<EOF
interface=wlan0
dhcp-range=10.0.0.2,10.0.0.5,255.255.255.0,12h
EOF

cat > /etc/hostapd/hostapd.conf <<EOF
interface=wlan0
driver=nl80211
hw_mode=g
channel=6
ieee80211n=1
wmm_enabled=1
ht_capab=[HT40][SHORT-GI-20][DSSS_CCK-40]
macaddr_acl=0
auth_algs=1
wpa=2
wpa_key_mgmt=WPA-PSK
wpa_passphrase=G3DT2000
ssid=G3DT2000
rsn_pairwise=CCMP
EOF


cat > /etc/rc.local <<EOF
#!/bin/sh -e
ifconfig wlan0 down
ifconfig wlan0 10.0.0.1 netmask 255.255.255.0 up
iwconfig wlan0 power off
service dnsmasq restart
service hostapd restart
hostapd -B /etc/hostapd/hostapd.conf & > /dev/null 2>&1
exit 0
EOF

cat > /etc/network/interfaces <<EOF
auto lo
iface lo inet loopback
iface eth0 inet manual
allow-hotplug wlan0
iface wlan0 inet dhcp
#wpa-conf /etc/wpa_supplicant/wpa_supplicant.conf
EOF


echo "AP All done! Reboot Now"
