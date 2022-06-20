<div align="center">
 <h1>  Burrows Wheeler Data Compression </h1>
 <img src="https://img.shields.io/badge/Language--lightgrey?style=for-the-badge&logo=C" alt="Python">
</div>

The Burrows Wheeler Data Compression algorithm is a data compression algorithm that is used to compress data.
It comprises of a series of steps that are executed in order to compress the data.

1. The BWT is a data transformation method that overhauls data in order to reduce the size of the modified message. In technical terms, it's a lexicographically reversible permutation of a string's characters. It is the first of three steps that must be followed in order to create the Burrows-Wheeler Data Compression method, which is the foundation for the Unix compression programme bzip2.

Example:<br>
<div align="center"> 

```Let the string be "TataMotors". This is transformed into "astTtMorao" after we perform BWT on it.```
</div>

2. MTF (Move to Front) is a data transformation method that restructures data in such a manner that the altered message is more compressible and may thus be utilised as an additional compression step. It's an invertible transform of a series of input characters to an array of output numbers in technical terms.

<div align="center">

</div>

3. The Huffman coding technique is a lossless data compression method. The concept is to give variable-length codes to input characters, the lengths of which are determined by the frequency of the related characters. The smallest code is assigned to the most often occurring character, whereas the biggest code is assigned to the least frequently occurring character.