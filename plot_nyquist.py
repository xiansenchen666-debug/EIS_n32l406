import re
import matplotlib.pyplot as plt

def plot_nyquist(filename):
    # Dictionary to store data for each channel: {channel_id: {'Z_real': [], 'Z_imag': []}}
    data = {
        0: {'Z_real': [], 'Z_imag': []},
        1: {'Z_real': [], 'Z_imag': []},
        2: {'Z_real': [], 'Z_imag': []}
    }

    # Regex to match data lines: EIS_DATA, Freq, Test_Count, CH, Real, Imag, Mag, Phase
    # Example: EIS_DATA, 0.1     , 1         , 0   , 0.101273       , -0.173915      , ...
    pattern = re.compile(r'EIS_DATA\s*,\s*[\d.]+\s*,\s*\d+\s*,\s*(\d+)\s*,\s*([-\d.]+)\s*,\s*([-\d.]+)')

    with open(filename, 'r', encoding='utf-8', errors='ignore') as f:
        for line in f:
            match = pattern.search(line)
            if match:
                ch = int(match.group(1))
                if ch in [0, 1, 2]:
                    # In Nyquist plots, we usually plot -Z'' on the y-axis, but standard is Z'' vs Z'.
                    # We will plot Z_real on X, and -Z_imag on Y as is standard for electrochemistry, 
                    # or just Z_real vs Z_imag. Let's stick to standard Nyquist (-Z_imag on Y).
                    # Convert from raw values to mOhm. 
                    # Assuming the current printed values are in Ohm, multiply by 1000 to get mOhm.
                    # Adjust this factor if the raw values have a different unit mapping.
                    z_real = float(match.group(2)) * 1000
                    z_imag = float(match.group(3)) * 1000
                    
                    data[ch]['Z_real'].append(z_real)
                    # For standard Nyquist, we usually plot negative imaginary part on Y axis
                    data[ch]['Z_imag'].append(-z_imag)

    plt.figure(figsize=(10, 8))
    
    # Plot each channel
    for ch in [0, 1, 2]:
        if data[ch]['Z_real']:
            plt.plot(data[ch]['Z_real'], data[ch]['Z_imag'], marker='o', linestyle='-', label=f'Channel {ch}')
            
            # Optional: Annotate start and end points
            plt.annotate(f'Start', (data[ch]['Z_real'][0], data[ch]['Z_imag'][0]), textcoords="offset points", xytext=(0,10), ha='center', fontsize=8)
            plt.annotate(f'End', (data[ch]['Z_real'][-1], data[ch]['Z_imag'][-1]), textcoords="offset points", xytext=(0,-15), ha='center', fontsize=8)

    plt.title('Nyquist Plot (Channels 0, 1, 2) - Scaled to mOhm')
    plt.xlabel("Z' (Real) [mOhm]")
    plt.ylabel("-Z'' (Negative Imaginary) [mOhm]")
    plt.grid(True)
    plt.legend()
    plt.axhline(y=0, color='k', linestyle='--', alpha=0.3)
    plt.axvline(x=0, color='k', linestyle='--', alpha=0.3)
    
    # Make axes equal to preserve shapes
    plt.axis('equal')
    
    plt.savefig('nyquist_plot_ch012.png', dpi=300, bbox_inches='tight')
    print("Nyquist plot saved as 'nyquist_plot_ch012.png'")

if __name__ == '__main__':
    plot_nyquist('xsh136A.tmp.txt')
