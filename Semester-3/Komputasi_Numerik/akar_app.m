function akar_app()
    % Input fungsi & interval
    fx_str = inputdlg('Masukkan fungsi f(x), contoh: @(x) x.^2+4*x-21');
    f = str2func(fx_str{1});

    a = str2num(inputdlg('Masukkan batas kiri a:'){1});
    b = str2num(inputdlg('Masukkan batas kanan b:'){1});
    tol = str2num(inputdlg('Masukkan toleransi:'){1});
    max_iter = str2num(inputdlg('Masukkan iterasi maksimal:'){1});

    % Jalankan Bisection
    root_bisec = bisection(f, a, b, tol, max_iter);

    % Jalankan Regula-Falsi
    root_regula = regula_falsi(f, a, b, tol, max_iter);

    % Tampilkan hasil
    hasil = sprintf('Hasil Bisection = %.6f\nHasil Regula-Falsi = %.6f', root_bisec, root_regula);
    msgbox(hasil, 'Hasil Akar');
end

% Tambahkan fungsi Bisection & Regula-Falsi
function root = bisection(f, a, b, tol, max_iter)
    fprintf('\nIterasi   a          b          c          f(c)\n');
    for k = 1:max_iter
        c = (a+b)/2; %tiitk tengah interval
        fprintf('%3d   %10.6f  %10.6f  %10.6f  %10.6f\n', k, a, b, c, f(c));
        if f(a)*f(c) < 0
            b = c;
        else
            a = c;
        end
        if abs(f(c)) < tol || abs(b-a) < tol
            root = c;
            return
        end
    end
    root = (a+b)/2;
end

function root = regula_falsi(f, a, b, tol, max_iter)
    fprintf('\nIterasi   a          b          c          f(c)\n');
    for k = 1:max_iter
        c = (a*f(b)-b*f(a))/(f(b)-f(a)); %rumus interpolasi linear
        fprintf('%3d   %10.6f  %10.6f  %10.6f  %10.6f\n', k, a, b, c, f(c));
        if abs(f(c)) < tol %kondisi stop
            root = c;
            return
        end
        if f(a)*f(c) < 0
            b = c;
        else
            a = c;
        end
    end
    root = c;
end

