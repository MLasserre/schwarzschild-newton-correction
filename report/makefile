PROJECT = report
BIBFILE = biblio
TEX = pdflatex -shell-escape -interaction=nonstopmode -file-line-error
BIB = bibtex

.PHONY: all clean superclean spell

all: $(PROJECT).pdf

$(PROJECT).pdf : $(PROJECT).tex $(BIBFILE).bib
	$(TEX) $(PROJECT).tex
	$(BIB) $(PROJECT)
	$(TEX) $(PROJECT).tex
	$(TEX) $(PROJECT).tex


$(PROJECT).bbl $(PROJECT).blg : $(BIBFILE).bib $(PROJECT).aux
	$(BIB) $(PROJECT)
	
$(PROJECT).aux : $(PROJECT).tex
	$(TEX) $(PROJECT).tex

$(PROJECT).bib : $(PROJECT).tex
	$(TEX) $(PROJECT).tex

spell::
	ispell *.tex

clean::
	rm -fv *.aux *.log *.bbl *.blg *.toc *.out *.lot *.lof

superclean::
	rm -fv *.aux *.log *.bbl *.blg *.toc *.out *.lot *.lof $(PROJECT).pdf

