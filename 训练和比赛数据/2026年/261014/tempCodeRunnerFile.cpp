        cnt_l -= l / a[i];
        for (int j = 0; j < i; j++) {
            cnt_l += l / (a[i] * a[j]);
        }
    }