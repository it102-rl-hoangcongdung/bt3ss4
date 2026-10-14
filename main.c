#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    if (n <= 0) {
        printf("Loi nghiep vu: Tong so giao dịch N phai lon hon 0.\n");
        return 0;
    }

    long long tong_doanh_thu = 0;

    for (int i = 1; i <= n; i++) {
        int ma_do_uong, size, topping, the_gold;
        if (scanf("%d", &ma_do_uong) != 1) {
            break;
        }

        if (ma_do_uong == -1) {
            if (i == 1) {
                tong_doanh_thu = 0;
            }
            break;
        }

        if (ma_do_uong == 0) {
            scanf("%d %d %d", &size, &topping, &the_gold);
            continue;
        }

        if (scanf("%d %d %d", &size, &topping, &the_gold) != 3) {
            continue;
        }

        if (ma_do_uong < 1 || ma_do_uong > 3) {
            continue;
        }

        if (size < 1 || size > 3 || topping < 0 || topping > 5) {
            continue;
        }

        long long gia_co_ban = 0;
        if (ma_do_uong == 1) {
            gia_co_ban = 29000;
        } else if (ma_do_uong == 2) {
            gia_co_ban = 39000;
        } else if (ma_do_uong == 3) {
            gia_co_ban = 49000;
        }

        long long phu_thu_size = 0;
        if (size == 2) {
            phu_thu_size = 6000;
        } else if (size == 3) {
            phu_thu_size = 10000;
        }

        long long phu_thu_topping = (long long)topping * 8000;
        long long tong_tien_mon = gia_co_ban + phu_thu_size + phu_thu_topping;

        if (the_gold == 1) {
            tong_tien_mon = (tong_tien_mon * 90) / 100;
        }

        tong_doanh_thu += tong_tien_mon;
    }

    printf("Tong doanh thu ca lam việc: %lld VNĐ\n", tong_doanh_thu);
    return 0;
}