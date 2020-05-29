*version 9.1 336684916
u 450
HB? 7
D? 2
R? 2
@libraries
@analysis
@targets
@attributes
@translators
a 0 u 13 0 0 0 hln 100 PCBOARDS=PCB
a 0 u 13 0 0 0 hln 100 PSPICE=PSPICE
a 0 u 13 0 0 0 hln 100 XILINX=XILINX
@setup
unconnectedPins 0
connectViaLabel 0
connectViaLocalLabels 0
NoStim4ExtIFPortsWarnings 1
AutoGenStim4ExtIFPorts 1
@index
pageloc 1 0 12277 
@status
c 120:04:29:12:40:03;1590748803
*page 1 0 970 720 iA
@ports
@parts
block 301 blocksym301 340 360 h
a 0 x 0:13 0 0 0 hln 100 PKGREF=KY-019
a 0 xp 9 0 0 0 hln 100 REFDES=KY-019
*symbol blocksym301
d 
@type p
@attributes
a 0 sp 9 0 0 0 hln 100 REFDES=HB?
a 0 s 0 0 0 0 hln 100 PART=
@pins
p 2 68 15 hrb 100 - l 70 10 u
a 0 s 0:13 0 0 -10 hln 100 ERC=o
a 0 s 0:13 0 0 -10 hln 100 FLOAT=n
a 0 s 1 0 71 8 hln 100 PIN=
p 2 68 25 hrb 100 + l 70 20 u
a 0 s 0:13 0 0 -10 hln 100 ERC=o
a 0 s 0:13 0 0 -10 hln 100 FLOAT=n
a 0 s 1 0 71 18 hln 100 PIN=
p 2 68 35 hrb 100 S l 70 30 u
a 0 s 0:13 0 0 -10 hln 100 ERC=o
a 0 s 0:13 0 0 -10 hln 100 FLOAT=n
a 0 s 1 0 71 28 hln 100 PIN=
p 2 2 35 hlb 100 NO l 0 30 h
a 0 s 0:13 0 0 -10 hln 100 ERC=i
a 0 s 0:13 0 0 -10 hln 100 FLOAT=n
a 0 s 1 0 1 28 hln 100 PIN=
p 2 2 25 hlb 100 COM l 0 20 h
a 0 s 0:13 0 0 -10 hln 100 ERC=i
a 0 s 0:13 0 0 -10 hln 100 FLOAT=n
a 0 s 1 0 1 18 hln 100 PIN=
p 2 2 15 hlb 100 NC l 0 10 h
a 0 s 0:13 0 0 -10 hln 100 ERC=i
a 0 s 0:13 0 0 -10 hln 100 FLOAT=n
a 0 s 1 0 1 8 hln 100 PIN=
@graphics 70 40 0 0 10
r 0 0 0 70 40
*end blocksym
block 319 blocksym319 340 410 h
a 0 x 0:13 0 0 0 hln 100 PKGREF=220AC/12VDC
a 0 xp 9 0 6 12 hln 100 REFDES=220AC/12VDC
*symbol blocksym319
d 
@type p
@attributes
a 0 sp 9 0 0 0 hln 100 REFDES=HB?
a 0 s 0 0 0 0 hln 100 PART=
@pins
p 2 2 55 hlb 100 L l 0 50 h
a 0 s 0:13 0 0 0 hln 100 ERC=i
a 0 s 0:13 0 0 0 hln 100 FLOAT=n
a 0 s 1 0 1 48 hln 100 PIN=
p 2 2 65 hlb 100 N l 0 60 h
a 0 s 0:13 0 0 0 hln 100 ERC=i
a 0 s 0:13 0 0 0 hln 100 FLOAT=n
a 0 s 1 0 1 58 hln 100 PIN=
p 2 168 15 hrb 100 + l 170 10 u
a 0 s 0:13 0 0 0 hln 100 ERC=o
a 0 s 0:13 0 0 0 hln 100 FLOAT=n
a 0 s 1 0 171 8 hln 100 PIN=
p 2 168 25 hrb 100 - l 170 20 u
a 0 s 0:13 0 0 0 hln 100 ERC=o
a 0 s 0:13 0 0 0 hln 100 FLOAT=n
a 0 s 1 0 171 18 hln 100 PIN=
@graphics 170 70 0 0 10
r 0 0 0 170 70
*end blocksym
block 316 blocksym316 490 250 h
a 0 x 0:13 0 0 0 hln 100 PKGREF=Step-Down
a 0 xp 9 0 2 52 hln 100 REFDES=Step-Down
*symbol blocksym316
d 
@type p
@attributes
a 0 sp 9 0 0 0 hln 100 REFDES=HB?
a 0 s 0 0 0 0 hln 100 PART=
@pins
p 2 50 100 hcb 100 IN- l 50 100 v
a 0 s 0:13 0 0 0 hln 100 ERC=i
a 0 s 0:13 0 0 0 hln 100 FLOAT=n
a 0 s 1 0 51 98 hln 100 PIN=
p 2 10 100 hcb 100 IN+ l 10 100 v
a 0 s 0:13 0 0 0 hln 100 ERC=i
a 0 s 0:13 0 0 0 hln 100 FLOAT=n
a 0 s 1 0 11 98 hln 100 PIN=
p 2 10 0 hct 100 OUT+ l 10 0 d
a 0 s 0:13 0 0 0 hln 100 ERC=i
a 0 s 0:13 0 0 0 hln 100 FLOAT=n
a 0 s 1 0 11 -2 hln 100 PIN=
p 2 50 0 hct 100 OUT- l 50 0 d
a 0 s 0:13 0 0 0 hln 100 ERC=i
a 0 s 0:13 0 0 0 hln 100 FLOAT=n
a 0 s 1 0 51 -2 hln 100 PIN=
@graphics 60 100 0 0 10
r 0 0 0 60 100
*end blocksym
block 3 blocksym3 310 70 h
a 0 x 0:13 0 0 0 hln 100 PKGREF=SerrArduino
a 0 xp 9 0 0 -6 hln 100 REFDES=SerrArduino
*symbol blocksym3
d 
@type p
@attributes
a 0 sp 9 0 0 0 hln 100 REFDES=HB?
a 0 s 0 0 0 0 hln 100 PART=
@pins
p 2 2 74 hlb 100 RW l 0 70 h
a 0 s 0:13 0 0 20 hln 100 ERC=i
a 0 s 0:13 0 0 20 hln 100 FLOAT=n
a 0 s 1 0 1 68 hln 100 PIN=
p 2 2 64 hlb 100 RS l 0 60 h
a 0 s 0:13 0 0 20 hln 100 ERC=i
a 0 s 0:13 0 0 20 hln 100 FLOAT=n
a 0 s 1 0 1 58 hln 100 PIN=
p 2 2 34 hlb 100 VSS l 0 30 h
a 0 s 0:13 0 0 20 hln 100 ERC=i
a 0 s 0:13 0 0 20 hln 100 FLOAT=n
a 0 s 1 0 1 28 hln 100 PIN=
p 2 2 44 hlb 100 VDD l 0 40 h
a 0 s 0:13 0 0 20 hln 100 ERC=i
a 0 s 0:13 0 0 20 hln 100 FLOAT=n
a 0 s 1 0 1 38 hln 100 PIN=
p 2 2 54 hlb 100 V0 l 0 50 h
a 0 s 0:13 0 0 20 hln 100 ERC=i
a 0 s 0:13 0 0 20 hln 100 FLOAT=n
a 0 s 1 0 1 48 hln 100 PIN=
p 2 2 114 hlb 100 D6 l 0 110 h
a 0 s 0:13 0 0 20 hln 100 ERC=i
a 0 s 0:13 0 0 20 hln 100 FLOAT=n
a 0 s 1 0 1 108 hln 100 PIN=
p 2 2 124 hlb 100 D7 l 0 120 h
a 0 s 0:13 0 0 20 hln 100 ERC=i
a 0 s 0:13 0 0 20 hln 100 FLOAT=n
a 0 s 1 0 1 118 hln 100 PIN=
p 2 2 134 hlb 100 A l 0 130 h
a 0 s 0:13 0 0 20 hln 100 ERC=i
a 0 s 0:13 0 0 20 hln 100 FLOAT=n
a 0 s 1 0 1 128 hln 100 PIN=
p 2 2 144 hlb 100 K l 0 140 h
a 0 s 0:13 0 0 20 hln 100 ERC=i
a 0 s 0:13 0 0 20 hln 100 FLOAT=n
a 0 s 1 0 1 138 hln 100 PIN=
p 2 2 104 hlb 100 D5 l 0 100 h
a 0 s 0:13 0 0 20 hln 100 ERC=i
a 0 s 0:13 0 0 20 hln 100 FLOAT=n
a 0 s 1 0 1 98 hln 100 PIN=
p 2 2 94 hlb 100 D4 l 0 90 h
a 0 s 0:13 0 0 20 hln 100 ERC=i
a 0 s 0:13 0 0 20 hln 100 FLOAT=n
a 0 s 1 0 1 88 hln 100 PIN=
p 2 2 84 hlb 100 E l 0 80 h
a 0 s 0:13 0 0 20 hln 100 ERC=i
a 0 s 0:13 0 0 20 hln 100 FLOAT=n
a 0 s 1 0 1 78 hln 100 PIN=
p 2 2 174 hlb 100 SIGNAL_1 l 0 170 h
a 0 s 0:13 0 0 0 hln 100 ERC=i
a 0 s 0:13 0 0 0 hln 100 FLOAT=n
a 0 s 1 0 1 168 hln 100 PIN=
p 2 2 184 hlb 100 VDD_1 l 0 180 h
a 0 s 0:13 0 0 0 hln 100 ERC=o
a 0 s 0:13 0 0 0 hln 100 FLOAT=n
a 0 s 1 0 1 178 hln 100 PIN=
p 2 2 194 hlb 100 GND_1 l 0 190 h
a 0 s 0:13 0 0 0 hln 100 ERC=i
a 0 s 0:13 0 0 0 hln 100 FLOAT=n
a 0 s 1 0 1 188 hln 100 PIN=
p 2 2 224 hlb 100 MOTOR_VDD l 0 220 h
a 0 s 0:13 0 0 0 hln 100 ERC=i
a 0 s 0:13 0 0 0 hln 100 FLOAT=n
a 0 s 1 0 1 218 hln 100 PIN=
p 2 2 234 hlb 100 MOTOR_GND l 0 230 h
a 0 s 0:13 0 0 0 hln 100 ERC=i
a 0 s 0:13 0 0 0 hln 100 FLOAT=n
a 0 s 1 0 1 228 hln 100 PIN=
p 2 328 34 hrb 100 TERMO_1 l 330 30 u
a 0 s 0:13 0 0 0 hln 100 ERC=o
a 0 s 0:13 0 0 0 hln 100 FLOAT=n
a 0 s 1 0 331 28 hln 100 PIN=
p 2 328 44 hrb 100 TERMO_2 l 330 40 u
a 0 s 0:13 0 0 0 hln 100 ERC=o
a 0 s 0:13 0 0 0 hln 100 FLOAT=n
a 0 s 1 0 331 38 hln 100 PIN=
p 2 328 64 hrb 100 PHOTO_1 l 330 60 u
a 0 s 0:13 0 0 0 hln 100 ERC=o
a 0 s 0:13 0 0 0 hln 100 FLOAT=n
a 0 s 1 0 331 58 hln 100 PIN=
p 2 328 74 hrb 100 PHOTO_2 l 330 70 u
a 0 s 0:13 0 0 0 hln 100 ERC=o
a 0 s 0:13 0 0 0 hln 100 FLOAT=n
a 0 s 1 0 331 68 hln 100 PIN=
p 2 328 104 hrb 100 GND_2 l 330 100 u
a 0 s 0:13 0 0 0 hln 100 ERC=o
a 0 s 0:13 0 0 0 hln 100 FLOAT=n
a 0 s 1 0 331 98 hln 100 PIN=
p 2 328 114 hrb 100 + l 330 110 u
a 0 s 0:13 0 0 0 hln 100 ERC=o
a 0 s 0:13 0 0 0 hln 100 FLOAT=n
a 0 s 1 0 331 108 hln 100 PIN=
p 2 328 124 hrb 100 SW l 330 120 u
a 0 s 0:13 0 0 0 hln 100 ERC=o
a 0 s 0:13 0 0 0 hln 100 FLOAT=n
a 0 s 1 0 331 118 hln 100 PIN=
p 2 328 134 hrb 100 DT l 330 130 u
a 0 s 0:13 0 0 0 hln 100 ERC=o
a 0 s 0:13 0 0 0 hln 100 FLOAT=n
a 0 s 1 0 331 128 hln 100 PIN=
p 2 328 144 hrb 100 CLK l 330 140 u
a 0 s 0:13 0 0 0 hln 100 ERC=o
a 0 s 0:13 0 0 0 hln 100 FLOAT=n
a 0 s 1 0 331 138 hln 100 PIN=
p 2 328 174 hrb 100 G l 330 170 u
a 0 s 0:13 0 0 0 hln 100 ERC=o
a 0 s 0:13 0 0 0 hln 100 FLOAT=n
a 0 s 1 0 331 168 hln 100 PIN=
p 2 328 184 hrb 100 R l 330 180 u
a 0 s 0:13 0 0 0 hln 100 ERC=o
a 0 s 0:13 0 0 0 hln 100 FLOAT=n
a 0 s 1 0 331 178 hln 100 PIN=
p 2 328 194 hrb 100 Y l 330 190 u
a 0 s 0:13 0 0 0 hln 100 ERC=o
a 0 s 0:13 0 0 0 hln 100 FLOAT=n
a 0 s 1 0 331 188 hln 100 PIN=
p 2 328 214 hrb 100 SIGNAL_3 l 330 210 u
a 0 s 0:13 0 0 0 hln 100 ERC=o
a 0 s 0:13 0 0 0 hln 100 FLOAT=n
a 0 s 1 0 331 208 hln 100 PIN=
p 2 328 224 hrb 100 VDD_3 l 330 220 u
a 0 s 0:13 0 0 0 hln 100 ERC=o
a 0 s 0:13 0 0 0 hln 100 FLOAT=n
a 0 s 1 0 331 218 hln 100 PIN=
p 2 328 234 hrb 100 GND_3 l 330 230 u
a 0 s 0:13 0 0 0 hln 100 ERC=o
a 0 s 0:13 0 0 0 hln 100 FLOAT=n
a 0 s 1 0 331 228 hln 100 PIN=
@graphics 330 420 0 0 10
r 0 0 0 330 420
*end blocksym
part 419 R 570 420 d
a 0 sp 0 0 0 10 hlb 100 PART=R
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=RC05
a 0 s 0:13 0 0 0 hln 100 GATE=
a 0 a 0:13 0 0 0 hln 100 PKGREF=R1
a 0 ap 9 0 15 0 hln 100 REFDES=R1
a 0 u 13 0 17 39 hln 100 VALUE=10K
part 418 d 570 380 d
a 0 s 0:13 0 0 0 hln 100 PKGTYPE=
a 0 x 0:13 0 0 0 hln 100 PKGREF=LED
a 0 xp 9 0 15 0 hln 100 REFDES=LED
block 318 blocksym318 390 50 h
a 0 x 0:13 0 0 0 hln 100 PKGREF=ArduinoUNO-Rev3
a 0 xp 9 0 0 -2 hln 100 REFDES=ArduinoUNO-Rev3
*symbol blocksym318
d 
@type p
@attributes
a 0 sp 9 0 0 0 hln 100 REFDES=HB?
a 0 s 0 0 0 0 hln 100 PART=
@pins
@graphics 160 180 0 0 10
r 0 0 0 160 180
*end blocksym
block 317 blocksym317 390 250 h
a 0 x 0:13 0 0 0 hln 100 PKGREF=RTC-3231
a 0 xp 9 0 2 50 hln 100 REFDES=RTC-3231
*symbol blocksym317
d 
@type p
@attributes
a 0 sp 9 0 0 0 hln 100 REFDES=HB?
a 0 s 0 0 0 0 hln 100 PART=
@pins
p 2 10 0 hct 100 GND l 10 0 d
a 0 s 0:13 0 0 0 hln 100 ERC=i
a 0 s 0:13 0 0 0 hln 100 FLOAT=n
a 0 s 1 0 11 -2 hln 100 PIN=
p 2 30 0 hct 100 VCC l 30 0 d
a 0 s 0:13 0 0 0 hln 100 ERC=i
a 0 s 0:13 0 0 0 hln 100 FLOAT=n
a 0 s 1 0 31 -2 hln 100 PIN=
p 2 70 0 hct 100 SCL l 70 0 d
a 0 s 0:13 0 0 0 hln 100 ERC=i
a 0 s 0:13 0 0 0 hln 100 FLOAT=n
a 0 s 1 0 71 -2 hln 100 PIN=
p 2 50 0 hct 100 SDA l 50 0 d
a 0 s 0:13 0 0 0 hln 100 ERC=i
a 0 s 0:13 0 0 0 hln 100 FLOAT=n
a 0 s 1 0 51 -2 hln 100 PIN=
@graphics 80 100 0 0 10
r 0 0 0 80 100
*end blocksym
part 1 titleblk 960 720 h
a 1 s 13 0 350 10 hcn 100 PAGESIZE=A
a 1 s 13 0 180 60 hcn 100 PAGETITLE=
a 1 u 13 0 10 10 hln 100 CompanyName=Z-Amps, Inc.
a 1 u 13 0 10 20 hln 100 Line1=
a 1 u 13 0 10 30 hln 100 Line2=
a 1 u 13 0 10 40 hln 100 Line3=
a 1 u 13 0 150 95 hln 100 Date=May 29, 2020
a 1 s 13 0 340 95 hrn 100 PAGECOUNT=1
a 1 s 13 0 300 95 hrn 100 PAGENO=1
@conn
w 273
s 640 300 660 300 272
w 271
s 640 290 660 290 270
w 269
s 640 280 660 280 268
w 267
s 640 260 660 260 266
w 265
s 640 250 660 250 264
w 263
s 640 240 660 240 262
w 261
s 640 210 660 210 260
w 259
s 640 200 660 200 258
w 257
s 640 190 660 190 256
w 255
s 640 180 660 180 254
w 253
s 640 170 660 170 252
w 251
s 640 140 660 140 250
w 245
s 640 130 660 130 244
w 243
s 640 110 660 110 242
w 241
s 640 100 660 100 240
w 239
s 290 300 310 300 238
w 237
s 290 290 310 290 236
w 235
s 290 260 310 260 234
w 233
s 290 250 310 250 232
w 202
s 290 240 310 240 230
s 310 210 290 210 55
s 310 210 310 240 227
s 310 200 290 200 53
s 310 200 310 210 219
s 310 190 290 190 51
s 310 190 310 200 216
s 310 180 290 180 45
s 310 180 310 190 212
s 310 170 290 170 39
s 310 160 290 160 33
s 310 160 310 170 207
s 310 170 310 180 206
s 290 140 310 140 16
s 310 150 290 150 110
s 310 140 310 150 191
s 310 150 310 160 193
w 25
s 310 120 290 120 26
w 23
s 290 110 310 110 22
w 21
s 290 100 310 100 20
w 19
s 290 130 310 130 18
w 305
s 410 380 430 380 304
w 307
s 410 390 430 390 306
w 311
s 340 390 290 390 310
w 313
s 340 380 290 380 312
w 315
s 340 370 290 370 314
w 303
s 430 370 410 370 302
w 321
s 290 460 340 460 320
w 323
s 290 470 340 470 322
w 341
s 500 250 500 240 340
w 343
s 540 250 540 240 342
w 359
s 400 240 400 250 358
w 361
s 420 240 420 250 360
w 357
s 460 250 440 250 348
s 460 240 460 250 334
s 440 240 440 250 362
w 391
s 530 420 510 420 370
s 500 350 500 370 430
s 570 380 570 370 421
s 500 370 530 370 432
s 530 370 570 370 436
s 530 420 530 370 434
w 428
s 530 460 570 460 426
s 530 430 510 430 409
s 600 460 600 360 437
s 600 360 540 360 439
s 540 360 540 350 441
s 530 460 530 430 443
s 570 460 600 460 445
w 449
s 570 420 570 410 448
@junction
j 640 300
+ p 3 GND_3
+ w 273
j 640 290
+ p 3 VDD_3
+ w 271
j 640 280
+ p 3 SIGNAL_3
+ w 269
j 640 260
+ p 3 Y
+ w 267
j 640 250
+ p 3 R
+ w 265
j 640 240
+ p 3 G
+ w 263
j 640 210
+ p 3 CLK
+ w 261
j 640 200
+ p 3 DT
+ w 259
j 640 190
+ p 3 SW
+ w 257
j 640 180
+ p 3 +
+ w 255
j 640 170
+ p 3 GND_2
+ w 253
j 640 140
+ p 3 PHOTO_2
+ w 251
j 640 130
+ p 3 PHOTO_1
+ w 245
j 640 110
+ p 3 TERMO_2
+ w 243
j 640 100
+ p 3 TERMO_1
+ w 241
j 310 300
+ p 3 MOTOR_GND
+ w 239
j 310 290
+ p 3 MOTOR_VDD
+ w 237
j 310 260
+ p 3 GND_1
+ w 235
j 310 250
+ p 3 VDD_1
+ w 233
j 310 240
+ p 3 SIGNAL_1
+ w 202
j 310 210
+ p 3 K
+ w 202
j 310 200
+ p 3 A
+ w 202
j 310 190
+ p 3 D7
+ w 202
j 310 180
+ p 3 D6
+ w 202
j 310 170
+ p 3 D5
+ w 202
j 310 160
+ p 3 D4
+ w 202
j 310 140
+ p 3 RW
+ w 202
j 310 150
+ p 3 E
+ w 202
j 310 120
+ p 3 V0
+ w 25
j 310 110
+ p 3 VDD
+ w 23
j 310 100
+ p 3 VSS
+ w 21
j 310 130
+ p 3 RS
+ w 19
j 410 380
+ p 301 +
+ w 305
j 410 390
+ p 301 S
+ w 307
j 340 390
+ p 301 NO
+ w 311
j 340 380
+ p 301 COM
+ w 313
j 340 370
+ p 301 NC
+ w 315
j 410 370
+ p 301 -
+ w 303
j 340 460
+ p 319 L
+ w 321
j 340 470
+ p 319 N
+ w 323
j 460 250
+ p 317 SCL
+ w 357
j 440 250
+ p 317 SDA
+ w 357
j 400 250
+ p 317 GND
+ w 359
j 420 250
+ p 317 VCC
+ w 361
j 500 250
+ p 316 OUT+
+ w 341
j 540 250
+ p 316 OUT-
+ w 343
j 510 420
+ p 319 +
+ w 391
j 510 430
+ p 319 -
+ w 428
j 500 350
+ p 316 IN+
+ w 391
j 530 370
+ w 391
+ w 391
j 540 350
+ p 316 IN-
+ w 428
j 570 380
+ p 418 1
+ w 391
j 570 460
+ p 419 2
+ w 428
j 570 410
+ p 418 2
+ w 449
j 570 420
+ p 419 1
+ w 449
@attributes
a 0 s 0:13 0 0 0 hln 100 PAGETITLE=
a 0 s 0:13 0 0 0 hln 100 PAGENO=1
a 0 s 0:13 0 0 0 hln 100 PAGESIZE=A
a 0 s 0:13 0 0 0 hln 100 PAGECOUNT=1
@graphics
