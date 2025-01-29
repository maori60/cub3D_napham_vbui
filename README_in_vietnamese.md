# cub3D_napham_vbui

## Dự án Cub3D - Trường 42

### Mô Tả
Dự án này nhằm mục đích tạo ra một trò chơi 2D sử dụng các khái niệm raycasting. Mục tiêu chính là quản lý một bản đồ và các texture trong một tệp `.cub`, với các tệp `.xpm` cho các texture. Trò chơi sử dụng thư viện **MLX** để hiển thị đồ họa.

Dự án được chia thành nhiều phần: phân tích cú pháp tệp `.cub`, quản lý texture và màu sắc, xác thực tham số và xử lý hiển thị và di chuyển của người chơi.

---

## Cấu Trúc Dự Án

### Các Tệp Phân Tích (Parsing Files)

Phân tích cú pháp được chia thành nhiều tệp để xử lý các phần khác nhau của tệp `.cub`. Dưới đây là các tệp chính:

- **args_checker.c**: Kiểm tra các đối số khi chạy chương trình, chủ yếu là xem tệp `.cub` có hợp lệ không.
- **file_loader.c**: Tải tệp `.cub` vào mảng chuỗi và xác thực cú pháp (texture, màu sắc, bản đồ, vv).
- **texture_checker.c**: Kiểm tra tính hợp lệ của các texture trong tệp `.cub`.
- **map_boundaries.c**: Đảm bảo rằng bản đồ được bao quanh bởi các bức tường cả theo chiều ngang và chiều dọc.
- **map_loader.c**: Tải bản đồ, xử lý các bức tường và đảm bảo nó được hình thành đúng.
- **map_validator.c**: Xác thực cú pháp của bản đồ, đảm bảo rằng chỉ có các ký tự hợp lệ (`0`, `1`, `N`, `S`, `E`, `W`).
- **player_position.c**: Xử lý vị trí của người chơi trên bản đồ.
- **rgb_parser.c**: Quản lý phân tích cú pháp màu sắc RGB cho sàn và trần.

---

### Các Tệp Thêm

- **cub3d.h**: Chứa tất cả các khai báo cấu trúc được sử dụng trong dự án (`t_data`, `t_mapinfo`, vv).
- **utils.c**: Chứa các hàm tiện ích cho việc xử lý lỗi và giải phóng bộ nhớ.
- **main.c**: Điểm vào của chương trình, khởi tạo dữ liệu và tải tệp `.cub`.

---

## Quy Trình Phân Tích

1. **Kiểm Tra Tệp**: Kiểm tra xem tệp `.cub` có hợp lệ và các tệp `.xpm` có thể truy cập được không.
2. **Tải Tệp**: Tải tệp `.cub` vào một mảng chuỗi để xử lý.
3. **Xác Thực Texture và Màu Sắc**: Kiểm tra đường dẫn đến các texture `.xpm` và chuyển đổi màu sắc của sàn và trần sang giá trị hex.
4. **Xác Thực Bản Đồ**: Đảm bảo rằng bản đồ được bao quanh bởi các bức tường và sử dụng các ký tự hợp lệ.
5. **Vị Trí Người Chơi**: Đảm bảo rằng chỉ có một người chơi và họ được đặt đúng vị trí trên bản đồ.

---

### Chạy Chương Trình

Để chạy chương trình, hãy truyền đường dẫn đến tệp `.cub` như là đối số:

```bash
./cub3d <path/to/map.cub>
