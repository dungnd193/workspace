use QLBongDa;
-- Buổi 3
-- a. Xử lý chuỗi, ngày giờ
-- 1. Cho biết NGAYTD, TENCLB1, TENCLB2, KETQUA các trận đấu diễn ra vào tháng 3 trên sân nhà mà không bị thủng lưới.
select NGAYTD, clb1.TENCLB as TENCLB1, clb2.TENCLB as TENCLB2, KETQUA
from TRANDAU td, CAULACBO clb1, CAULACBO clb2
where MONTH(NGAYTD)=3 AND td.MACLB1 = clb1.MACLB and td.MACLB2 = clb2.MACLB
AND ((clb1.MASAN = td.MASAN AND KETQUA LIKE '%-0') OR (clb2.MASAN = td.MASAN AND KETQUA LIKE '0-%'))

-- 2. Cho biết mã số, họ tên, ngày sinh của những cầu thủ có họ lót là “Công”.
SELECT MACT, HOTEN, NGAYSINH
FROM CAUTHU
WHERE HOTEN LIKE N'% Công %'

-- 3. Cho biết mã số, họ tên, ngày sinh của những cầu thủ có họ không phải là họ “Nguyễn “.
SELECT MACT, HOTEN, NGAYSINH
FROM CAUTHU
WHERE HOTEN NOT LIKE N'%Nguyễn %'

-- 4. Cho biết mã huấn luyện viên, họ tên, ngày sinh, địa chỉ của những huấn luyện viên Việt Nam có tuổi nằm trong khoảng 35-40.
SELECT MAHLV, TENHLV as HoTen,NGAYSINH, DIACHI 
FROM  HUANLUYENVIEN as hlv
WHERE (year(getDate())-year(NGAYSINH)>=35)
AND (year(getDate())-year(NGAYSINH)<=40)

select MAHLV, TENHLV, NGAYSINH, DIACHI, (year(getdate()) - year(NGAYSINH)) AS TUOI
from HUANLUYENVIEN, QUOCGIA
where HUANLUYENVIEN.MAQG = QUOCGIA.MAQG
and TENQG = N'Việt Nam'
and (((year(getdate()) - year(NGAYSINH)) >= 35 and (year(getdate()) - year(NGAYSINH)) <= 40))

-- 5. Cho biết tên câu lạc bộ có huấn luyện viên trưởng sinh vào ngày 20 tháng 8 năm 2019.

select TENCLB
from CAULACBO, HUANLUYENVIEN, HLV_CLB
where (day(NGAYSINH) = 20 and month(NGAYSINH) = 8 and year(NGAYSINH) = 2019)
and HUANLUYENVIEN.MAHLV = HLV_CLB.MAHLV
and CAULACBO.MACLB = HLV_CLB.MACLB

-- 6. Cho biết tên câu lạc bộ, tên tỉnh mà CLB đang đóng có số bàn thắng nhiều nhất tính đến hết vòng 3 năm 2009.



-- b. Truy vấn con
-- 1. Cho biết mã câu lạc bộ, tên câu lạc bộ, tên sân vận động, địa chỉ và số lượng cầu thủ nước
-- ngoài (Có quốc tịch khác “Việt Nam”) tương ứng của các câu lạc bộ có nhiều hơn 2 cầu thủ nước ngoài.

select tb1.MACLB, TENCLB, TENSAN, DIACHI, SLCTNUOCNGOAI
from 
	(select MACLB, count(MACT) as SLCTNUOCNGOAI
	from CAUTHU ct, QUOCGIA qg
	where qg.TENQG != N'Việt Nam' and ct.MAQG = qg.MAQG
	group by MACLB
	having count(MACT) > 2 ) tb1
inner join 
	(select TENCLB, MACLB, TENSAN, DIACHI 
	from CAULACBO, SANVD
	where SANVD.MASAN = CAULACBO.MASAN) tb2
on (tb1.MACLB = tb2.MACLB)

-- 2. Cho biết tên câu lạc bộ, tên tỉnh mà CLB đang đóng có hiệu số bàn thắng bại cao nhất năm 2009.



-- 3. Cho biết danh sách các trận đấu ( NGAYTD, TENSAN, TENCLB1, TENCLB2, KETQUA) của
-- câu lạc bộ CLB có thứ hạng thấp nhất trong bảng xếp hạng vòng 3 năm 2009.

select NGAYTD, TENSAN, clb1.TENCLB as TENCLB1, clb2.TENCLB AS TENCLB2, KETQUA
from TRandAU td, CAULACBO clb1, CAULACBO clb2, SANVD svd, BANGXH bangxh
where bangxh.VONG = 3 and bangxh.NAM = 2009 and bangxh.HANG >= ALL(select HANG from BANGXH where VONG = 3 and NAM = 2009)
and td.MACLB1 = clb1.MACLB and td.MACLB2 = clb2.MACLB and td.MASAN = svd.MASAN and (bangxh.MACLB = clb1.MACLB or bangxh.MACLB = clb2.MACLB)

-- 4. Cho biết mã câu lạc bộ, tên câu lạc bộ đã tham gia thi đấu với tất cả các câu lạc bộ còn lại (kể cả sân nhà và sân khách) trong mùa giải năm 2009.

select MACLB, TENCLB
from CAULACBO clb 
where (select count(MATRAN) from TRandAU where TRandAU.NAM = 2009 and (TRandAU.MACLB1 = clb.MACLB or TRandAU.MACLB2 = clb.MACLB))
	= (select count(CAULACBO.MACLB) from CAULACBO) - 1

-- 5. Cho biết mã câu lạc bộ, tên câu lạc bộ đã tham gia thi đấu với tất cả các câu lạc bộ còn lại ( chỉ tính sân nhà) trong mùa giải năm 2009.

select MACLB, TENCLB
from CAULACBO clb 
where (select count(MATRAN) from TRandAU where TRandAU.MACLB1 = clb.MACLB or TRandAU.MACLB2 = clb.MACLB)
	= (select count(CAULACBO.MACLB) from CAULACBO) - 1

-- c. Bài tập về Rule
-- 1. Khi thêm cầu thủ mới, kiểm tra vị trí trên sân của cầu thủ chỉ thuộc một trong các vị trí sau: Thủ môn, tiền đạo, tiền vệ, trung vệ, hậu vệ.

alter table CAUTHU
add constraint constraint_vitri check (VITRI IN (N'Thủ môn', N'Tiền đạo', N'Tiền vệ', N'Trung vệ', N'Hậu vệ'));

-- 2. Khi phân công huấn luyện viên, kiểm tra vai trò của huấn luyện vi ên chỉ thuộc một trong các vai trò sau: HLV chính, HLV phụ, HLV thể lực, HLV thủ môn.

alter table HLV_CLB
add constraint constraint_vaitro check (VAITRO IN (N'HLV chính', N'HLV phụ', N'HLV thể lực', N'HLV thủ môn'));

-- 3. Khi thêm cầu thủ mới, kiểm tra cầu thủ đó có tuổi phải đủ 18 trở lên (chỉ tính năm sinh)

alter table CAUTHU
add constraint constraint_ngaysinh check (year(getdate()) - year(NGAYSINH) >= 18)

-- 4. Kiểm tra kết quả trận đấu có dạng số_bàn_thắng- số_bàn_thua.

alter table TRandAU
add constraint constraint_ketqua check (KETQUA LIKE '%-%')

-- d. Bài tập về View


-- 1. Cho biết mã số, họ tên, ngày sinh, địa chỉ và vị trí của các cầu thủ thuộc đội bón g “SHB Đà Nẵng” có quốc tịch “Bra-xin”.


-- 2. Cho biết kết quả (MATRAN, NGAYTD, TENSAN, TENCLB1, TENCLB2, KETQUA) các trận đấu vòng 3 của mùa bóng năm 2009.


-- 3. Cho biết mã huấn luyện viên, họ tên, ngày sinh, địa chỉ, vai trò và tên CLB đang làm việc của các huấn luyện viên có quốc tịch “Việt Nam”.


-- 4. Cho biết mã câu lạc bộ, tên câu lạc bộ, tên sân vận động, địa chỉ và số lượng cầu thủ
-- nước ngoài (có quốc tịch khác “Việt Nam”) tương ứng của các câu lạc bộ nhiều hơn 2 cầu thủ nước ngoài.


-- 5. Cho biết tên tỉnh, số lượng câu thủ đang thi đấu ở vị trí tiền đạo trong các câu lạc bộ thuộc địa bàn tỉnh đó quản lý.


-- 6. Cho biết tên câu lạc bộ,tên tỉnh mà CLB đang đóng nằm ở vị trí cao nhất của bảng xếp hạng của vòng 3 năm 2009.


-- 7. Cho biết tên huấn luyện viên đang nắm giữ một vị trí trong 1 câu lạc bộ mà chưa có số điện thoại.


-- 8. Liệt kê các huấn luyện viên thuộc quốc gia Việt Nam chưa làm công tác huấn luyện tại bất kỳ một câu lạc bộ


-- 9. Cho biết kết quả các trận đấu đã diễn ra (MACLB1, MACLB2, NAM, VONG, SOBANTHANG,SOBANTHUA).


-- 10. Cho biết kết quả các trận đấu trên sân nhà (MACLB, NAM, VONG, SOBANTHANG, SOBANTHUA).


-- 11. Cho biết kết quả các trận đấu trên sân khách (MACLB, NAM, VONG, SOBANTHANG,SOBANTHUA).


-- 12. Cho biết danh sách các trận đấu (NGAYTD, TENSAN, TENCLB1, TENCLB2, KETQUA) của câu lạc bộ CLB đang xếp hạng cao nhất tính đến hết vòng 3 năm 2009.


-- 13. Cho biết danh sách các trận đấu (NGAYTD, TENSAN, TENCLB1, TENCLB2, KETQUA) của câu lạc bộ CLB có thứ hạng thấp nhất trong bảng xếp hạng vòng 3 năm 2009.