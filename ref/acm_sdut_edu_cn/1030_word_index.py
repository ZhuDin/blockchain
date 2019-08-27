dict_base = {'a':1, 'b':2, 'c':3, 'd':4, 'e':5, 'f': 6, 'g':7,
              'h':8, 'i':9, 'j':10, 'k':11, 'l':12, 'm':13, 'n':14,
              'o':15, 'p':16, 'q':17, 'r':18, 's':19, 't':20, 
              'u':21, 'v':22, 'w':23, 'x':24, 'y':25, 'z':26}

dictionary = {'a':1, 'b':2, 'c':3, 'd':4, 'e':5, 'f': 6, 'g':7,
              'h':8, 'i':9, 'j':10, 'k':11, 'l':12, 'm':13, 'n':14,
              'o':15, 'p':16, 'q':17, 'r':18, 's':19, 't':20, 
              'u':21, 'v':22, 'w':23, 'x':24, 'y':25, 'z':26}

str_base = 'abcdefghijklmnopqrstuvwxyz'

label = 26

for char in str_base[:-1]:
    for alph in str_base[dict_base[char]:]:
        dictionary[char+alph] = label + 1
        label += 1

for one in str_base[:-2]:
    for two in str_base[dict_base[one]:]:
        for three in str_base[dict_base[two]:]:
            dictionary[one+two+three] = label + 1
            label +=1

for one in str_base[:-3]:
    for two in str_base[dict_base[one]:]:
        for three in str_base[dict_base[two]:]:
            for four in str_base[dict_base[three]:]:
                dictionary[one+two+three+four] = label + 1
                label += 1

for one in str_base[:-4]:
    for two in str_base[dict_base[one]:]:
        for three in str_base[dict_base[two]:]:
            for four in str_base[dict_base[three]:]:
                for five in str_base[dict_base[four]:]:
                    dictionary[one+two+three+four+five] = label + 1
                    label += 1

'''
a --- z :26
ab --- yz:325
    ab - az:25   bc - bz:24   cd - cz:23   de - dz:22   
    ef - ez:21   fg - fz:20   gh - gz:19   hi - hz:18
    ij - iz:17   jk - jz:16   kl - kz:15   lm - lz:14
    mn - mz:13   no - nz:12   op - oz:11   pq - pz:10
    qr - qz:9    rs - rz:8    st - sz:7    tu - tz:6
    uv - uz:5    vw - vz:4    wx - wz:3    xy - xz:2    yz:1
abc --- xyz:2600
    abc-ayz:300  bcd-byz:276  cde-cyz:253  def-dyz:231  
    efg-eyz:210  fgh-fyz:190  ghi-gyz:171  hij-hyz:153
    ijk-iyz:136  jkl-jyz:120  klm-kyz:105  lmn-lyz:91
    mno-myz:78   nop-nyz:66   opq-oyz:55   pqr-pyz:45
    qrs-qyz:36   rst-ryz:28   stu-syz:21   tuv-tyz:15
    uvw-uyz:10   vwx-vyz:6    wxy-wyz:3    xyz:1
abcd --- wxyz:14950
    abcd-axyz:2300 bcde-bxyz:2024 cdef-cxyz:1771 defg-dxyz:1540
    efgh-exyz:1330 fghi-fxyz:1140 ghij-gxyz:969  hijk-hxyz:816
    ijkl-ixyz:680  jklm-jxyz:560  klmn-kxyz:455  lmno-lxyz:364
    mnop-mxyz:286  nopq-nxyz:220  opqr-oxyz:165  pqrs-pxyz:120
    qrst-qxyz:84   rstu-rxyz:56   stuv-sxyz:35   tuvw-txyz:20
    uvwx-uxyz:10   vwxy-vxyz:4    wxyz:1
abcde --- vwxyz:65780
    abcde-awxyz:12650 bcdef-bwxyz:10626 cdefg-cwxyz:8855  defgh-dwxyz:7315
    efghi-ewxyz:5985  fghij-fwxyz:4845  ghijk-gwxyz:3876  hijkl-hwxyz:3060
    ijklm-iwxyz:2380  jklmn-jwxyz:1820  klmno-kwzyz:1365  lmnop-lwxyz:1001
    mnopq-mwxyz:715   nopqr-nwxyz:495   opqrs-owxyz:330   pqrst-pwxyz:210
    qrstu-qwxyz:126   rstuv-rwxyz:70    stuvw-swxyz:35    tuvwx-twxyz:15
    uvwxy-uwxyz:5     vwxyz:1
'''

while(1):
    string = input()
    total = 0
    if(string == ''.join(sorted(string))):
        total = dictionary[string]

    print(total)
