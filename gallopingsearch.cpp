// gallopingsearch.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <vector>

template <typename T> void gallopingsearch(const std::vector<T> &src_a, const std::vector<T>& src_b, std::vector<T> &dest)
{
    auto findlastelement = [](const std::vector<T>& src, size_t offset, const T& ref_element) -> size_t
    {
        const size_t full_len = src.size();
        size_t length = full_len - offset;
        size_t stepsize = 1u;
        while ((stepsize < length) && (ref_element == src[offset + stepsize]))
        {
            stepsize *= 2u;
        }
        if (stepsize >= length)
        {
            stepsize /= 2u;
        }
        size_t binsearch = stepsize + offset;
        size_t step = 0u;
        
        while (stepsize > 1u)
        {
            stepsize /= 2u;
            if (binsearch < full_len)
            {
                binsearch = (ref_element == src[binsearch]) ? binsearch + stepsize : binsearch - stepsize;
            }
            else
            {
                binsearch -= stepsize;
            }            
        }
        size_t index;
        if ((binsearch + 1u) < full_len && (ref_element == src[binsearch+1u])) {index = binsearch+1u;}
        else if ((offset < binsearch)   && (ref_element != src[binsearch])) { index = binsearch - 1u; }
        else { index = binsearch; }

        return index - offset;
    };

    size_t src_a_index=0u;
    size_t src_b_index=0u;
    dest.clear();

    const size_t a_size = src_a.size();
    const size_t b_size = src_b.size();
    if ((a_size > 0u) && (b_size > 0u))
    {
        do
        {
            const T& a = src_a[src_a_index];
            const T& b = src_b[src_b_index];
            if (a == b)
            {
                dest.push_back(src_a[src_a_index]);
                ++src_a_index;
                ++src_b_index;
                if ((src_a_index < a_size) && (src_b_index < b_size))
                {
                    const T& c = src_a[src_a_index];
                    const T& d = src_b[src_b_index];
                    if ((a == c) && (b == d))
                    {
                        src_a_index = findlastelement(src_a, src_a_index, a) + src_a_index + 1u;
                        src_b_index = findlastelement(src_b, src_b_index, b) + src_b_index + 1u;
                    }
                }
            }
            else if (a < b)
            {
                src_a_index = findlastelement(src_a, src_a_index, a) + src_a_index + 1u;
            }
            else
            {
                src_b_index = findlastelement(src_b, src_b_index, b) + src_b_index + 1u;
            }
        } while ((src_a_index < a_size) && (src_b_index < b_size));
    } 
}


int main()
{
    std::vector<size_t> a = { 1,2,3,3,3,3,3,4,4,5,5,6,7,7,7,9,12,16,35 };
    std::vector<size_t> b = { 1,2,3,3,3,3,3,3,3,3,4,4,4,5,5,5,5,5,5,5,5,5,6,7,7,7, 9,9,9,9, 35};
    std::vector<size_t> c;
    gallopingsearch(a, b, c);
    std::cout << "Hello World!\n";
}

// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
